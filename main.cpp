#include <iostream>
#include "SequenceGenerator.h"

int main() {
    // Работа с типом int
    std::cout << "=== Integer Sequence Generator ===" << std::endl;
    SequenceGenerator<int> intGenerator(5, 2);

    std::cout << "Initial: " << intGenerator.toString() << std::endl;
    std::cout << "Next: " << intGenerator.next() << std::endl; // 5
    std::cout << "Next: " << intGenerator.next() << std::endl; // 7
    std::cout << "Next: " << intGenerator.next() << std::endl; // 9
    std::cout << "After generation: " << intGenerator << std::endl;

    intGenerator.reset();
    std::cout << "After reset: " << intGenerator << std::endl;

    // Работа с типом double
    std::cout << "\n=== Double Sequence Generator ===" << std::endl;
    SequenceGenerator<double> doubleGenerator(1.5, 0.5);

    std::cout << "Initial (toString): " << doubleGenerator.toString() << std::endl;
    std::cout << "Next: " << doubleGenerator.next() << std::endl; // 1.5
    std::cout << "Next: " << doubleGenerator.next() << std::endl; // 2.0
    std::cout << "Peek next (without generation): " << doubleGenerator.peek() << std::endl; // 2.5
    std::cout << "Current state via << operator: " << doubleGenerator << std::endl;

    // Демонстрация оператора ввода
    std::cout << "\n=== Create new generator from input ===" << std::endl;
    SequenceGenerator<float> floatGenerator;
    std::cin >> floatGenerator; // Пользователь вводит start и step
    std::cout << "You entered: " << floatGenerator << std::endl;
    std::cout << "First value: " << floatGenerator.next() << std::endl;

    // Демонстрация clear()
    std::cout << "\n=== Clear demonstration ===" << std::endl;
    SequenceGenerator<int> testGen(100, 10);
    std::cout << "Before clear: " << testGen << std::endl;
    testGen.clear();
    std::cout << "After clear: " << testGen << std::endl;

    return 0;
}
