#include "consoledatasource.hpp"
#include <vector>
#include <iostream>
#include <sstream>

void ConsoleDataSource::read_data(){
    std::cout << "Enter data (space-separated numbers, leave one line empty to stop):" << std::endl;
        double value;
        std::string line;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        while (std::getline(std::cin, line)) {
            if (line.empty()) {
                break; // Stop if empty line is entered
            }
            std::istringstream iss(line);
            while (iss >> value) {
                data.push_back(value);
            }
        }
};

