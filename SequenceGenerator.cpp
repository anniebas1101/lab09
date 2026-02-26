#pragma once

#include "SequenceGenerator.h"
#include <sstream>

template<typename T>
SequenceGenerator<T>::SequenceGenerator() : currentValue(T()), step(T(1)) {}

template<typename T>
SequenceGenerator<T>::SequenceGenerator(T start, T stepValue) : currentValue(start), step(stepValue) {}

template<typename T>
T SequenceGenerator<T>::next() {
    T temp = currentValue;
    currentValue += step;
    return temp;
}

template<typename T>
T SequenceGenerator<T>::peek() const {
    return currentValue;
}

template<typename T>
void SequenceGenerator<T>::reset() {
    currentValue = T(); // Устанавливаем значение по умолчанию (0 для чисел)
}

template<typename T>
void SequenceGenerator<T>::setStart(T start) {
    currentValue = start;
}

template<typename T>
void SequenceGenerator<T>::setStep(T stepValue) {
    step = stepValue;
}

template<typename T>
std::string SequenceGenerator<T>::toString() const {
    std::ostringstream oss;
    oss << "Current: " << currentValue << ", Step: " << step;
    return oss.str();
}

template<typename T>
void SequenceGenerator<T>::clear() {
    // По логике "очистки" для генератора - сброс в начальное состояние
    currentValue = T();
    step = T(1);
}
