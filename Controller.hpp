#ifndef Controller_H
#define Controller_H

#include "Model.hpp"
#include "View.hpp"

using namespace std;

/*
    the controller accepts and handles user input. it observes the Model
    and manages the View
*/
class Controller{
    private:
        const Model* mod;
        const View* view;

    public:
        Controller(); //default constructor
        Controller(const Model*,const View*); //parameterized constructor


};


#endif/*CONTROLLER_H*/