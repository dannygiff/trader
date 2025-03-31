#include <iostream>
#include <iomanip>

#include "Item.hpp"

using namespace std;


int main()
{
    Item foo = Item();
    //name, val, wgt, qty
    Item bar("bar", 5, 1, 1);
    Item gold("gold", 100, 8, 14);

    foo.display();
    cout << endl;
    bar.display();
    cout << endl;
    gold.display();
}
