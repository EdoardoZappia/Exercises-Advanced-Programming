#ifndef LOGTRANSFORMER_HPP
#define LOGTRANSFORMER_HPP

#include "datatransformer.hpp"
#include "datasource.hpp"

class LogTransformer : public DataTransformer{

public:
    LogTransformer(DataSource *source) : DataTransformer(source) {}
    void transform() override {
        for (double& value : source->data) {
            if (value < 0){
                value = 0;
            } else {
                value = log(value + 1);
            }
        }
    }
};

#endif // LOGTRANSFORMER_HPP