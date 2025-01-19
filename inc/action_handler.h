#pragma once

class ActionHandler {
    public:
        enum class Action {
            Multiply,
            Add,
            Subtract
        };

        // Метод для умножения
        template <typename T>
        T multiply(const T a, const T b);

        // Метод для сложения
        template <typename T>
        T add(const T a, const T b);

        // Метод для вычитания
        template <typename T>
        T subtract(const T a, const T b);

        // Функция-обертка для выполнения действий
        template <typename T>
        T execute(Action action, T a, T b);

};