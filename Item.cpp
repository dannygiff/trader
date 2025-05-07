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

void Item::setQty(int q)
{
    qty = q;
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

void Item::save(fstream &outfile)//writes the item to binary file
{
    //outfile should already be open
    
    //write name
    int nameLen = this->name.size();
    outfile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen)); //write size 
    outfile.write(name.c_str(), nameLen);//write name

    //write value
    outfile.write( reinterpret_cast<const char *>(&value), sizeof(value));

    //write qty
    outfile.write( reinterpret_cast<const char *>(&qty), sizeof(qty));
}

Item Item::load(fstream &infile)
{
    //infile should already be open

    string name;
    int value;
    int qty;

    //get name length
    int nameLen = 0;
    infile.read( reinterpret_cast<char *>( &nameLen ), sizeof( nameLen ) );

    //get name
    char* temp = new char[nameLen + 1];
    infile.read( temp, nameLen );
    temp[nameLen] = '\0';
    name = temp;

    //get value
    infile.read( reinterpret_cast<char *>( &value ), sizeof( value ) );

    //get qty
    infile.read( reinterpret_cast<char *>( &qty ), sizeof( qty ) );

    return Item(name, value, qty);
}