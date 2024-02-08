#include "filedatasource.hpp"
#include <iostream>
#include <string> 
#include <fstream>

FileDataSource::FileDataSource(const std::string filename) : DataSource("FileDataSource"), filename(filename) {
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
    }
};

FileDataSource::~FileDataSource() {
    std::cout << "FileDataSource destructor called" << std::endl;
    std::ifstream file(filename);
    if (file.is_open())
    {
        file.close();
    };
};

void FileDataSource::read_data(){
    std::ifstream file(filename);
    if (file.is_open()) {
        std::cout << "Reading data from file " << filename << std::endl;
        std::string line;
        while (std::getline(file, line)) {
            double value = std::stod(line);
            data.push_back(value);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file\n";
    }
};
