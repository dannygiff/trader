#include "User.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

User::User()
{
    name = "";
    admin = false;
    currency = 0;
}

User::User(string n, bool a, int c)
{
    name = n;
    admin = a;
    currency = c;
}


void User::save(fstream &outfile)
{
    //outfile should be successfully opened before this is called
    int namelen = 0;

    //write name
    namelen = this->name.size();
    outfile.write(reinterpret_cast<const char*>(&namelen), sizeof(namelen)); //write size 
    outfile.write(name.c_str(), namelen);//write name

    //write admin flag
    outfile.write( reinterpret_cast<const char *>(&admin), sizeof(admin));

    //write currency
    outfile.write( reinterpret_cast<const char *>(&currency), sizeof(currency));

    // //write cart
    // int cartlen = cart.size();
    // outfile.write( reinterpret_cast<const char *>(&cartlen), sizeof(cartlen));//write vector size
    // if (!cart.empty())
    // {
    //     for (int i=0; i<cart.size(); i++)
    //     {
    //         outfile.write(reinterpret_cast<const char*>(&i), sizeof(i)); //write index
    //         cart.at(i).save(outfile);
    //     }
    // }
}

User User::loadFromFile(fstream &infile)
{
    string name;
    bool admin;
    int currency;

    //get name length
    int nameLen = 0;
    infile.read( reinterpret_cast<char *>( &nameLen ), sizeof( nameLen ) );

    //get name
    char* temp = new char[nameLen + 1];
    infile.read( temp, nameLen );
    temp[nameLen] = '\0';
    name = temp;

    //get admin
    infile.read( reinterpret_cast<char *>( &admin ), sizeof( admin ) );

    //get currency
    infile.read( reinterpret_cast<char *>( &currency ), sizeof( currency ) );
    delete [] temp;
    return User(name, admin, currency);
}

void User::login()
{
    
    /* this function goes in handler maybe?
    string filename = "userdata.bin"; //change filename here
    fstream userFile;
    vector<User> userData;

    userFile.open(filename, ios::in | ios::out | ios::binary);
    if(userFile.fail())
    {
        cout << "\nuserdata file does not exist. Creating a new one...";
        this->genFile(filename);
    }
    */
    //cout << "\nPlease enter a username: ";

}

void User::print()
{
    cout << "Username: " << setw(10) << name << "  "
         << "Admin: " << (this->getAdmin()? 'T' : 'F') << "  "
         << "Currency: " << setw(6) << currency << endl;
}
