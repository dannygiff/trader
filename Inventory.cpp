#include "Inventory.hpp"

Inventory::Inventory()
{
    name = "";
    size = 0;
    items = 0;
}

Inventory::Inventory(int sz)
{
    name = "";
    size = sz;

    items = new Item[sz];
    //for(int i=0; i<sz; i++)

}

void Inventory::setName(string nm)
{
    //input validation?
    name = nm;
}

void Inventory::setSize(int sz)
{
    //input validation?
    size = sz;
}

void Inventory::fill()//fill the inventory with random items
{
    for(int i=0; i<this->size; i++)
    {
        this->items[i].generate();
    }
}

void Inventory::display()
{
    cout << endl << getName() << "'s inventory";
    for(int i=0; i<this->size; i++)
    {
        cout << endl;
        this->items[i].display();
    }
}

Inventory::~Inventory()
{
    delete [] items;
}
