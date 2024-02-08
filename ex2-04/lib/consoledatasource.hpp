#ifndef CONSOLEDATASOURCE_HPP
#define CONSOLEDATASOURCE_HPP

#include "datasource.hpp"

class ConsoleDataSource : public DataSource{
    
    public:
       ConsoleDataSource() : DataSource("ConsoleDataSource") {};
       ~ConsoleDataSource() override = default;
       void read_data() override;

};

#endif // CONSOLEDATASOURCE_HPP