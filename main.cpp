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

    //setup
    Handler ctrl;
    string ufname = "userdata.dat"; //userdata filename
    string cfname = "cartdata.dat"; //cartdata filename

    //userdata test
    ctrl.genUserFile(ufname);
    ctrl.loadRecord(ufname);
    User foo("foo", false, 20);
    ctrl.addtoRecord(foo);
    ctrl.saveRecord(ufname);
    ctrl.printRecord();
   

    //cartdata test
    ctrl.genCartFile(cfname);
    ctrl.readCartFile(cfname);
    ctrl.printCarts();

    //shopping test
    ctrl.setUser(foo);
    cout << "\nadding an item to foo's inventory" << endl;
    Item bar("bar", 25, 13);
    ctrl.addToCart(bar);
    
}
