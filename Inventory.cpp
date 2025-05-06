#include "Inventory.hpp"
#include <iomanip>

void Inventory::header()
{
    cout << endl << getName() << "'s inventory" << endl;
    bar(40);
    cout << endl;
    cout << endl;
}

void Inventory::bar(int n)
{
    for (int i=0; i<n; i++)
        cout << "=";
}

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
    header();
    for(int i=0; i<this->size; i++)
    {
        cout << setw (2) << i+1 << " ";
        this->items[i].display();
        cout << endl;
    }
    bar(40);
}

Inventory::~Inventory()
{
    delete [] items;
}
