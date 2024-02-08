#ifndef DATATRANSFORMER_HPP
#define DATATRANSFORMER_HPP

#include "datasource.hpp"

class DataTransformer {
    protected:
        DataSource* source;
    public:
        DataTransformer(DataSource *source) : source(source) {}
        virtual ~DataTransformer() {}
        virtual void transform() = 0;
};

#endif // DATATRANSFORMER_HPP