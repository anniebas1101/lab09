#pragma once

#include <iostream>
#include <string>

template <typename T>
class SequenceGenerator {
private:
    T currentValue;
    T step;

public:
    // Конструкторы
    SequenceGenerator();
    SequenceGenerator(T start, T stepValue);

    // Генерация следующего значения (постфиксная и префиксная формы)
    T next();               // возвращает текущее и переходит к следующему
    T peek() const;         // посмотреть следующее значение без генерации

    // Сброс генератора
    void reset();
    void setStart(T start);
    void setStep(T stepValue);

    // Методы, требуемые заданием
    std::string toString() const;
    void clear(); // Сброс к начальным значениям по умолчанию (аналог очистки)

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const SequenceGenerator<T>& obj) {
        os << "SequenceGenerator: current = " << obj.currentValue << ", step = " << obj.step;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SequenceGenerator<T>& obj) {
        std::cout << "Enter start value: ";
        is >> obj.currentValue;
        std::cout << "Enter step value: ";
        is >> obj.step;
        return is;
    }
};

// Поскольку это шаблон, реализации обычно подключаются здесь же
#include "SequenceGenerator.cpp"
