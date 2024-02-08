#ifndef DATASOURCE_HPP
#define DATASOURCE_HPP

#include <iostream>
#include <string>
#include <vector>

class DataSource
{
protected:
    const std::string name;
    std::vector<double> data;
public:

    friend class DataTransformer;
    friend class LinearScaler;
    friend class StandardScaler;
    friend class LogTransformer;

    DataSource(const std::string name) : name(name) {};
    DataSource(const std::string name, std::vector<double> data) : name(name) {
        for (size_t i = 0; i < sizeof(data); ++i) {
            this->data.push_back(data[i]);
        }
    };
    virtual ~DataSource() {};

    void display_info(){
        std::cout << "Name: " << name << std::endl;
        if (data.empty())
            std::cout << "Data: " << "empty" << std::endl;
        else
            std::cout << "Data: " << this << std::endl;
        //std::cout << this << std::endl; 
    };

    virtual void read_data() = 0;
    

    friend std::ostream& operator<<(std::ostream& os, DataSource *ds) {
        for (size_t i = 0; i < ds->data.size(); ++i) {
            os << ds->data[i] << " ";
        }
        os << std::endl;
        return os;
    }
};

#endif // DATASOURCE_HPP
