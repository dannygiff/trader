#ifndef Model_H
#define Model_H

#include <vector>
#include "Inventory.hpp"
#include "Item.hpp"

using namespace std;


/*
the model contains core program data: items, inventories, player data
it is independent of the controller and the view
*/
class Model{
    private:
        Inventory playerInv; //user inventory
        Inventory shop;      //shop inventory
        Item* catalog;       //all items
        vector<Item> cart;   //cart of items to be checked

    public:
        Model(); //default constructor

};

#endif/*MODEL_H*/