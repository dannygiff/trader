#ifndef Item_H
#define Item_H

#include <iostream>
#include <string>

using namespace std;

class Item {
        private:
            string name;
            int value;
            int weight;
            int qty;
            //string desc;
        protected:
        public:
            Item();
            Item(string, int, int, int);

            //getters
            string getName(){ return name; }
            int getVal(){ return value; }
            int getWgt(){ return weight; }
            int getQty(){ return qty; }

            //setters


            //fns
            void display();
            void generate();
};

#endif