#ifndef STANDARDSCALER_HPP
#define STANDARDSCALER_HPP

#include "datatransformer.hpp"
#include "datasource.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

class StandardScaler : public DataTransformer{

public:
    StandardScaler(DataSource *source) : DataTransformer(source) {}
    void transform() override {
        std::vector<double> &d = source->data;
        double mean = std::accumulate(d.begin(), d.end(), 0.0) / d.size();

        double sum_squared_diff = std::inner_product(d.begin(), d.end(), d.begin(), 0.0);
        double std_dev = std::sqrt(sum_squared_diff / d.size() - mean * mean);

        for (double& value : d) {
            value = (value - mean) / std_dev;
        }
    }
};

#endif // STANDARDSCALER_HPP