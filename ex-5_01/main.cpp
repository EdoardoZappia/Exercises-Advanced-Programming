#include "lib/calculator.hpp"


int main(){

    Calculator calculator;
    double a, b;

    std::cout << "Choose an operation: \n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    int choice;
    std::cin >> choice;
    std::cout << "" << std::endl;
    std::cout << "Enter the numbers: " << std::endl;
    std::cin >> a;
    std::cin >> b;
    switch (choice)
    {
    case 1:
        std::cout << calculator.add(a, b ) << std::endl;
        break;
    case 2:
        std::cout << calculator.subtract(a, b ) << std::endl;
        break;
    case 3:  
        std::cout << calculator.multiply(a, b ) << std::endl;
        break;
    case 4:
        std::cout << calculator.divide(a, b ) << std::endl;
        break;
    default:
        throw std::invalid_argument("Invalid choice\n");
        break;
    }
    return 0;
}