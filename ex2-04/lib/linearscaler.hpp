#ifndef LINEARSCALER_HPP
#define LINEARSCALER_HPP

#include "datatransformer.hpp"
#include "datasource.hpp"

class LinearScaler : public DataTransformer{
private:
    double scaling_factor;
public:
    LinearScaler(DataSource *source, double scaling_factor) : DataTransformer(source), scaling_factor(scaling_factor) {}
    void transform() override {
        for (double& value : source->data) {
            value *= scaling_factor;
        }
    }
};

#endif // LINEARSCALER_HPP
