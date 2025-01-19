#include "action_handler.h"

// Метод для умножения
template <typename T> 
T ActionHandler::multiply(const T a, const T b) {
    return a * b;
}

// Метод для сложения
template <typename T> 
T ActionHandler::add(const T a, const T b) {
    return a + b;
}

// Метод для вычитания
template <typename T> 
T ActionHandler::subtract(const T a, const T b) {
    return a - b;
}

// Реализация функции-обертки
template <typename T>
T ActionHandler::execute(Action action, T a, T b) {
    switch (action) {
        case Action::Multiply:
            return multiply(a, b);
        case Action::Add:
            return add(a, b);
        case Action::Subtract:
            return subtract(a, b);
        default:
            throw "Unknown action";
    }
}



// Явные инстанцирования шаблонных методов
template int ActionHandler::multiply<int>(int a, int b);
template double ActionHandler::multiply<double>(double a, double b);

template int ActionHandler::add<int>(int a, int b);
template double ActionHandler::add<double>(double a, double b);

template int ActionHandler::subtract<int>(int a, int b);
template double ActionHandler::subtract<double>(double a, double b);

template int ActionHandler::execute<int>(Action action, int a, int b);
template double ActionHandler::execute<double>(Action action, double a, double b);
