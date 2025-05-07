#ifndef Inventory_H
#define Inventory_H

#include <iostream>
#include <string>
#include <vector>

#include "Item.hpp"

using namespace std;

class Inventory {
    private:
        string name;
        int size;
        Item *items;
        vector<Item> itemV;

        //helper functions
        void header();
        void bar(int);
    protected:
    public:
        Inventory();
        Inventory(int);

        string getName(){return name;}
        int getSize(){return size;}

        void setName(string);
        void setSize(int);

        void fill();
        void fill(int);
        void sample();
        void display();
        void displayV();

        ~Inventory();
};

#endif //INVENTORY_H