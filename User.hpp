#ifndef User_H
#define User_H

#include <string>
#include <vector>
#include <fstream>

#include "Item.hpp"

using namespace std;

/*
    the user class contains an identifier and several personal variables for each unique user
*/
class User{
    private:
        string name;
        bool admin;        //is the user an admin
        int currency;      //coins, points, etc.
        vector<Item> cart; //cart of Items

        //utility functions
        void findUser();
    public:
        User(); //default constructor
        User(string, bool, int);

        string getName(){return name;}
        bool getAdmin(){return admin;}
        int getCurrency(){return currency;}

        void genFile(string); //generates a new userdata file
        void save(fstream&);
        void login();


        ~User();
};


#endif //USER_H