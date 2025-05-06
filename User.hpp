#ifndef User_H
#define User_H

#include <string>
#include <vector>

#include "Item.hpp"

using namespace std;

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

        void write();
        void login();


        ~User();
};


#endif //USER_H