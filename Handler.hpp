#ifndef Handler_h
#define Handler_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
        Inventory* shop; //what shop are they looking at

        int nUsers;      //how many users on record
        vector<User> userRecord;

        bool quit;
        bool goodInput;
    public:
        Handler();
        Handler(User, Inventory);

        //user record functions
        void genFile();
        void loadRecord();
        void saveRecord();
        void addtoRecord(User);
        int findUser(string);

        //shopping functions
        void menu();
        void purchase();

        void getInput();
        User getUser();
};

#endif //HANDLER_H