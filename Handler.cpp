#include "Handler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cctype>

#include "Item.hpp"
#include "Inventory.hpp"
#include "User.hpp"

Handler::Handler()
{

}

Handler::Handler(string userFileName, string cartFileName)
{
    fstream uFile, cFile;
    
    //check for user record
    uFile.open(userFileName, ios::in | ios::out | ios::binary);
    if(!uFile)
    {
        this->genUserFile(userFileName);
    }
    this->loadRecord(userFileName);
    uFile.close();

    //check for cart data
    cFile.open(cartFileName, ios::in | ios::out | ios::binary);
    if(!cFile)
    {
        this->genCartFile(cartFileName);
    }
    this->readCartFile(cartFileName);
    cFile.close();
}

void Handler::genUserFile(string filename)
{
    cout << "generating " << filename << endl;

    User admn("Admin", true, 99999);//generic administrator
    User test("test", false, 69);
    nUsers = 2;

    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);
    outfile.write( reinterpret_cast<const char *>(&nUsers), sizeof(nUsers));
    admn.save(outfile);
    test.save(outfile);
    outfile.close();
}

void Handler::printRecord()
{
    for(int i=0; i<userRecord.size(); i++)
    {
        cout << i << " ";
        userRecord.at(i).print();
    }
}

void Handler::loadRecord(string filename)
{
    fstream infile;
    
    int nameLen;
    infile.open(filename, ios::in | ios::binary);

    infile.read( reinterpret_cast<char *>( &nUsers ), sizeof( nUsers ) );

    for(int i=0; i<nUsers; i++)
    {
        User temp;
        userRecord.push_back(temp.loadFromFile(infile));
    }
    infile.close();
}

void Handler::saveRecord(string filename)
{
    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);

    //write size of vector
    int vecSize = userRecord.size();
    outfile.write( reinterpret_cast<const char *>(&vecSize), sizeof(vecSize));
    
    //write vector
    for (int i=0; i<vecSize; i++)
    {
        //write each user
        userRecord.at(i).save(outfile);
    }
    outfile.close();
    
}

void Handler::addtoRecord(User u)
{
    this->userRecord.push_back(u);
    this->nUsers = this->userRecord.size();
}

void Handler::login()
{
    string input = "";
    int pos;
    cout << "Please enter a username: ";
    // do not let the user enter an empty string as a username
    do {
        getline(std::cin, input);
        if (input == "") {
            cout << "Error - Please enter a valid username: ";
        }
    } while (input == "");

    pos = findUser(input);
    //cout << "\npos = " << pos;
    if(pos >= 0)
    {
        this->setUser(userRecord[pos]);
        cout << "Welcome back " << user.getName() << endl;
    }else{
        User temp(input, false, 1000);
        userRecord.push_back(temp);
        this->setUser(temp);
        cout << "Created new user " << user.getName() << endl;
    }
}

int Handler::findUser(string target)
{
    int pos = -1;
    //cout << "\nsearching for: " << target;
    for(int i=0; i<userRecord.size(); i++)
    {
        if(userRecord.at(i).getName() == target)
        {
            //cout << "\nFound " << userRecord.at(i).getName() << " (" << target << ")";
            return i;
        }
            
    }

    return -1;
}

void Handler::genCartFile(string filename)
{
    cout << "generating " << filename << endl;

    string admn = "Admin";
    string test = "test";
    Inventory a_inv(admn);
    a_inv.fill(1);
    Inventory t_inv(test);
    t_inv.fill(3);
    map<string, Inventory> m = {{admn, a_inv}, {test, t_inv}};

    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);

    //write size of map
    int mSize = m.size();
    outfile.write( reinterpret_cast<const char *>(&mSize), sizeof(mSize));

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        int nameLen = it->first.length();
        outfile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen)); //write size of name

        outfile.write(it->first.c_str(), nameLen);//write name

        
        it->second.save(outfile);
    }

    outfile.close();
}

void Handler::readCartFile(string filename)
{
    fstream infile;
    
    int mapSize;
    infile.open(filename, ios::in | ios::binary);

    infile.read( reinterpret_cast<char *>( &mapSize ), sizeof( mapSize ) );//read cart(map) size

    for(int i=0; i<mapSize; i++)
    {
        string name;
        //get name length
        int nameLen = 0;
        infile.read( reinterpret_cast<char *>( &nameLen ), sizeof( nameLen ) );

        //get name
        char* temp = new char[nameLen + 1];
        infile.read( temp, nameLen );
        temp[nameLen] = '\0';
        name = temp;

        //insert
        Inventory tempInv;
        cartData.insert({name, tempInv.load(infile) }); 

        //cleanup
        delete [] temp;
    }
    infile.close();
}

void Handler::saveCartFile(string filename)
{
    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);

    //write size of map
    int mSize = cartData.size();
    outfile.write( reinterpret_cast<const char *>(&mSize), sizeof(mSize));

    for (auto it = cartData.begin(); it != cartData.end(); ++it)
    {
        int nameLen = it->first.length();
        outfile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen)); //write size of name

        outfile.write(it->first.c_str(), nameLen);//write name

        
        it->second.save(outfile);
    }

    outfile.close();
}

void Handler::printCarts()
{
    for (auto it = cartData.begin(); it != cartData.end(); ++it)
    {
        it->second.setName(it->first);
        it->second.display();
        cout << endl;
    }
}

void Handler::addToCart(Item itm)
{
    //find the user's cart
    auto it = cartData.find(user.getName());
    if (it != cartData.end())
    {
        it->second.addItem(itm);
    }else{
        //or make a new one
        Inventory temp(itm);
        cartData.insert({user.getName(), temp});
    }
}

void Handler::showUserCart()
{
    //find the user's cart
    auto it = cartData.find(user.getName());
    if (it != cartData.end())
    {
        it->second.setName(it->first);
        it->second.display();
        cout << endl;
    }else{
        cout << "\nError - could not find user cart" << endl;
    }
}

void Handler::menu()
{
    bool quit = false;
    char choice;
    do
    {
        //menu prompt
        cout << "\nMenu (logged in as " << user.getName() <<  " )" << endl;
        cout << "1 - Change user" << endl;
        cout << "2 - View cart" << endl;
        cout << "3 - View shop" << endl;
        if(user.getAdmin())
            cout << "4 - View admin menu" << endl;
        cout << "q - Quit" << endl;

        //get choice
        cout << "\nEnter your choice: ";
        cin >> choice;

        //execute choice
        switch(choice)
        {
            case '1':
                cout << "Changing user...";
                this->login();
                break;
            case '2':
                cout << "Viewing cart...";
                this->showUserCart();
                break;
            case '3':
                cout << "Viewing items for sale...";
                this->browse();
                break;
            case '4':
                if(user.getAdmin())
                {
                    cout << "Viewing admin menu...";
                }else{
                    cout << "Error: " << user.getName() << " is not an admin";
                }
                break;
            case 'q':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again";
        }
        
    } while (choice != 'q');
}

void Handler::browse()
{
    char choice;
    int val;
    bool goodInput = false;
    Inventory store = this->getInv();
    do
    {
        store.display();
        cout << "\nEnter the item number you wish to purchase (or q to quit):" << endl;
        cin >> choice;

        if(choice == 'q')
        {
            goodInput = true;
        }else if (isdigit(choice)){
            val = choice - '0'; //ascii to int
            if(val > 0 && val < shop.getSize())
            {
                cout << "Purchasing " << store.getItemAt(val).getName();
                purchase(val);
                goodInput = true;
            }
        }
            

    } while (!goodInput);


    
}

void Handler::purchase(int pos)
{
    int quant;
    cout << "\nHow many are you buying? ";
    cin >> quant;
    if (quant < 0)
        quant = 0;
    if (quant > this->getInv().getItemAt(pos).getQty())
        quant = this->getInv().getItemAt(pos).getQty();
    addToCart(this->getInv().getItemAt(pos));
    this->getInv().remove(pos, quant);
}

void Handler::saveAll(string ufname, string cfname)
{
    this->saveRecord(ufname);
    this->saveCartFile(cfname);
}
