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

void User::login()
{
    string filename = "userdata.bin"; //change filename here

    
    cout << "\nPlease enter a username: ";

}
