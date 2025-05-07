#include "Inventory.hpp"
#include <iomanip>

void Inventory::header()
{
    cout << endl << getName() << "'s inventory" << endl;
    bar(40);
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
}

Inventory::Inventory(string nm)
{
    name = nm;
    size = 0;
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


void Inventory::fill(int n)
{
    for(int i=0; i<n; i++)
    {
        Item temp;
        temp.generate();
        this->items.push_back(temp);
    }
}

void Inventory::display()
{
    header();
    for(int i=0; i<this->items.size(); i++)
    {
        cout << setw (2) << i+1 << " ";
        this->items.at(i).display();
        cout << endl;
    }
    bar(40);
}

void Inventory::save(fstream &outfile)
{
    //outfile should be open
    int nItems = items.size();
    outfile.write( reinterpret_cast<const char *>(&nItems), sizeof(nItems));
    for (int i=0; i<nItems; i++)
    {
        items.at(i).save(outfile);
    }
}

Inventory Inventory::load(fstream &infile)
{
    //infile should be open
    int nItems = 0;
    infile.read( reinterpret_cast<char *>(&nItems), sizeof(nItems));

    Inventory temp;
    for(int i=0; i<nItems; i++)
    {
        Item d;
        temp.items.push_back(d.load(infile));
    }

    return temp;
}

Inventory::~Inventory()
{
    //delete [] items;
}
