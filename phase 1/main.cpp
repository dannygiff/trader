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

/*
        TODO:
        get input
        admin menu
        put it all together
*/

int main()
{
    //rand seed
    srand(static_cast<unsigned int>(time(0)));

    //setup
    string ufname = "userdata.dat"; //userdata filename
    string cfname = "cartdata.dat"; //cartdata filename
    Handler ctrl(ufname, cfname);
    Inventory test;
    test.fill(10);
    ctrl.setInv(test);
    
    ctrl.login();
    ctrl.menu();
    

    //save & quit
    ctrl.saveAll(ufname, cfname);
    return 0;
}
