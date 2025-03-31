#include <iostream>
#include <iomanip>

#include "Item.hpp"

using namespace std;

Item::Item()
{
    this->name = " ";
    this->value = 0;
    this->weight = 0;
    this->qty = 0;
}

Item::Item(string nam, int val, int wgt, int qt)
{
    this->name = nam;
    this->value = val;
    this->weight = wgt;
    this->qty = qt;
}

void Item::display()
{
    cout << setw(10) << this->getName() << " x" << setw(3) << left << this->getQty()
         << "  Value: " << setw(5) << left << this->getVal() * this->getQty()
         << " ("  << setw(3) << left << this->getVal() << ") "
         << "  Weight: " << setw(5) << left << this->getWgt() * this->getQty()
         << " ("  << setw(3) << left << this->getWgt()  << ") "
         << "  ";
}
