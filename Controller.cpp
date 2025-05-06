#include "Controller.hpp"

Controller::Controller()
{
    mod = NULL;
    view = NULL;
}

Controller::Controller(const Model* m, const View* v)
{
    this->mod = m;
    this->view = v;
}
