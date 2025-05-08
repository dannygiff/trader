#ifndef Handler_h
#define Handler_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "Item.hpp"
#include "Inventory.hpp"
#include "User.hpp"


/*
    the handler class manages program logic and flow. it is essentially a precursor to the controller and view classes
    coming later in the development process
*/
class Handler{
    private:
        User user;       //current logged in user
        Inventory shop; //what shop are they looking at

        int nUsers;              //how many users on record
        vector<User> userRecord; //the record

        map<string, Inventory> cartData; //associative container linking usernames to inventories

        bool quit;
        bool goodInput;
        
    public:
        Handler();
        Handler(string, string);

        //getters/setters
        int getNumUsers(){return nUsers;}
        Inventory getInv(){return shop;}
        void setUser(User u){user = u;}
        void setInv(Inventory in){shop = in;}

        //user record functions
        void genUserFile(string);   //generate userdata.dat file
        void printRecord();
        void loadRecord(string);
        void saveRecord(string);
        void addtoRecord(User);
        void login();
        int findUser(string);

        //cartData functions
        void genCartFile(string);     //generate cartdata.dat file
        void readCartFile(string);    //reads file into cartData map
        void saveCartFile(string);    //writes cartData to file
        void printCarts();            //prints all cartData (for testing)
        void addToCart(Item);
        void showUserCart();

        //shopping functions
        void menu();
        void browse();
        void purchase(int);

        void saveAll(string, string);
        void getInput();
        User getUser();
};

#endif //HANDLER_H