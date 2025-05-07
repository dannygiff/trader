#include "Handler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "Item.hpp"
#include "Inventory.hpp"
#include "User.hpp"



Handler::Handler()
{

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
    outfile.write( reinterpret_cast<const char *>(&nUsers), sizeof(nUsers));
    for (int i=0; i<nUsers; i++)
    {
        userRecord.at(i).save(outfile);
    }
    outfile.close();
    
}

void Handler::addtoRecord(User u)
{
    this->userRecord.push_back(u);
    this->nUsers = this->userRecord.size();
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
        //it->second.
    }

}
