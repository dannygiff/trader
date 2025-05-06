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
        User user;      //who is running the program
        Inventory* shop; //what shop are they looking at

        bool quit;
        bool goodInput;
    public:
        Handler();
        Handler(User, Inventory);

        void loadAll();
        void addUser();

        void menu();
        void purchase();

        void getInput();
        User getUser();
};

#endif //HANDLER_H