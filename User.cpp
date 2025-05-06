#include "User.hpp"

#include <iostream>
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

void User::genFile(string filename)
{
    User admn("Admin", true, 1000);//generic administrator

    fstream file;
    file.open(filename, ios::out | ios::binary);
    admn.save(file);

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

    //write cart
    int cartlen = cart.size();
    outfile.write( reinterpret_cast<const char *>(&cartlen), sizeof(cartlen));//write vector size

    
}

void User::login()
{
    string filename = "userdata.bin"; //change filename here
    fstream userFile;

    userFile.open(filename, ios::in | ios::out | ios::binary);
    if(userFile.fail())
    {
        cout << "\nuserdata file does not exist. Creating a new one...";
        this->genFile(filename);
    }

    //cout << "\nPlease enter a username: ";

}
