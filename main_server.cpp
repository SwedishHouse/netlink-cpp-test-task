#include <iostream>
#include "action_handler.h"


int main()
{
    ActionHandler act_handler;
    int arg1 = 5, arg2 = 2;
    std:: cout << "Hello world" << std::endl;
    std:: cout << "Add: " << act_handler.add<int>(arg1, arg2) << std::endl;
    std:: cout << "Sub: " << act_handler.add<int>(arg1, arg2) << std::endl;
    std:: cout << "Mult: " << act_handler.add<int>(arg1, arg2) << std::endl;
    return 0;
}