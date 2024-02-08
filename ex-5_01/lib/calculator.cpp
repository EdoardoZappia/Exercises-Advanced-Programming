#include "calculator.hpp"

double Calculator::add(const double &a, const double &b) {
    return a + b;
}

double Calculator::subtract(const double &a, const double &b) {
    return a - b;
}

double Calculator::multiply(const double &a, const double &b) {
    return a * b;
}

double Calculator::divide(const double &a, const double &b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}
