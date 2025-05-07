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
    public:
        User(); //default constructor
        User(string, bool, int);

        string getName(){return name;}
        bool getAdmin(){return admin;}
        int getCurrency(){return currency;}

        void save(fstream&);
        User loadFromFile(fstream&);    //loads a User from a file
        void login();

        void print();
        //~User();
};


#endif //USER_H