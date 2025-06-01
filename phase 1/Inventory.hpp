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
        vector<Item> items;

        //helper functions
        void header();
        void bar(int);
    protected:
    public:
        Inventory();
        Inventory(string);
        Inventory(Item);

        string getName(){return name;}
        int getSize(){return items.size();}
        Item getItemAt(int n){return items.at(n);}

        void setName(string);
        void setSize(int);

        void fill(int);
        void display();
        void addItem(Item);
        void remove(int, int);

        void save(fstream &);
        Inventory load(fstream &);

        ~Inventory();
};

#endif //INVENTORY_H