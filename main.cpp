#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Item.hpp"
#include "Inventory.hpp"

using namespace std;


int main()
{
    //rand seed
    srand(static_cast<unsigned int>(time(0)));


    Item foo = Item();
    //name, val, wgt, qty
    Item bar("bar", 5, 1, 1);
    Item gold("gold", 100, 8, 14);

    //random items
    Item r1, r2, r3;
    r1.generate();
    r2.generate();
    r3.generate();

    //item display
    foo.display();
    cout << endl;
    bar.display();
    cout << endl;
    gold.display();
    cout << endl;

    r1.display();
    cout << endl;
    r2.display();
    cout << endl;
    r3.display();
    cout << endl;

    //inventory test
    Inventory inv(10);
    inv.fill();
    inv.display();

}
