#ifndef Inventory_H
#define Inventory_H

#include <iostream>
#include <string>

#include "Item.hpp"

using namespace std;

class Inventory {
    private:
        string name;
        int size;
        Item *items;
    protected:
    public:
        Inventory();
        Inventory(int);

        string getName(){return name;}
        int getSize(){return size;}

        void setName(string);
        void setSize(int);

        void fill();
        void display();

        ~Inventory();
};

#endif