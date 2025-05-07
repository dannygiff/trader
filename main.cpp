#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Item.hpp"
#include "Inventory.hpp"
#include "User.hpp"
#include "Handler.hpp"

using namespace std;


int main()
{
    //rand seed
    srand(static_cast<unsigned int>(time(0)));

    //load users
    Handler ctrl;
    string ufname = "userdata.dat";
    string cfname = "cartdata.dat";

    ctrl.genUserFile(ufname);

    ctrl.loadRecord(ufname);
    User foo("foo", false, 20);
    ctrl.addtoRecord(foo);
    ctrl.saveRecord(ufname);

    ctrl.printRecord();
   
    // //inventory test
    // Inventory test;
    // test.fill(10);
    // test.display();

    ctrl.genCartFile(cfname);
    ctrl.readCartFile(cfname);
    ctrl.printCarts();
}
