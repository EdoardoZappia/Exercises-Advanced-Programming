#ifndef FILEDATASOURCE_HPP
#define FILEDATASOURCE_HPP

#include "datasource.hpp"

class FileDataSource : public DataSource {
    public:
    FileDataSource(const std::string filename);
    void read_data() override;
    ~FileDataSource() override;

    private:
        std::string filename;
};


#endif // FILEDATASOURCE_HPP