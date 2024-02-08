#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include <iostream>

class DataProcessor {

static unsigned int n_instances;

public:
    DataProcessor(double *data, const int size);
    ~DataProcessor() { delete[] data; }
    DataProcessor(const DataProcessor& other);
    int n_elements() const { return size; }

    double minimum() const;
    double maximum() const;
    double mean() const;
    double standard_deviation() const;

    friend std::ostream& operator<<(std::ostream& os, const DataProcessor& dp);
    double& operator[](const int index) const { return data[index]; }
    double& operator[](const int index) { return data[index]; }

    DataProcessor operator+(const DataProcessor &other) const;
    DataProcessor& operator=(const DataProcessor &other);

    static unsigned int get_n_instances() { return n_instances; }

private:
    double *data;
    int size;
};

double compute_correlation(const DataProcessor &dp1, const DataProcessor &dp2);

#endif // DATAPROCESSOR_HPP
