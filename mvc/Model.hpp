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
        Inventory shop;      //shop inventory 
        vector<Item> cart;   //cart of items to be checked
        //Item* catalog;       //all items
        //Inventory playerInv; //user inventory

    public:
        Model(); //default constructor

        ~Model();//destructor

};

#endif/*MODEL_H*/