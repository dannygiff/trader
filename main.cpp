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

    //load users

    //
    
    //random items
    Item r1, r2, r3;
    r1.generate();
    r2.generate();
    r3.generate();
    //item display
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
