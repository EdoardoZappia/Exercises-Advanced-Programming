#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>

class Calculator {
public:

    ~Calculator() = default;

    double add(const double &a, const double &b);
    double subtract(const double &a, const double &b);
    double multiply(const double &a, const double &b);
    double divide(const double &a, const double &b);
};

#endif