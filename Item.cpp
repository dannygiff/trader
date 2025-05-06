#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Item.hpp"

using namespace std;

Item::Item()
{
    this->name = " ";
    this->value = 0;
    //this->weight = 0;
    this->qty = 0;
}

Item::Item(string nam, int val, int qt)
{
    this->name = nam;
    this->value = val;
    //this->weight = wgt;
    this->qty = qt;
}

void Item::display()
{
    cout << setw(10) << this->getName() << " x" << setw(3) << left << this->getQty()
         << "  Value: " << setw(3) << left << this->getVal() << "  ("  
         << setw(5) << right << this->getVal() * this->getQty() << ") ";
         
         /*
         << "  Weight: " << setw(5) << left << this->getWgt() * this->getQty()
         << " ("  << setw(3) << left << this->getWgt()  << ") "
         << "  ";
         */
}

void Item::generate()//generates a random item
{
    this->name = "randItem";
    this->value = rand()%99 + 1;
    //this->weight = rand()%99 + 1;
    this->qty = rand()%9 + 1;
}
