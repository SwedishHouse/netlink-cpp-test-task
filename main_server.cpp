#include <iostream>
#include "action_handler.h"


int main()
{
    ActionHandler act_handler;
    int arg1 = 5, arg2 = 2;
    std:: cout << "Hello world from server" << std::endl;
    std:: cout << "Add: " << act_handler.execute<int>(ActionHandler::Action::ADD, arg1, arg2) << std::endl;
    std:: cout << "Sub: " << act_handler.execute<int>(ActionHandler::Action::SUBSTRACT, arg1, arg2) << std::endl;
    std:: cout << "Mult: " << act_handler.execute<int>(ActionHandler::Action::MULTIPLY, arg1, arg2) << std::endl;
    return 0;
}