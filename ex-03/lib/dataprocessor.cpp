#include "dataprocessor.hpp"

unsigned int DataProcessor::n_instances = 0;

DataProcessor::DataProcessor(const DataProcessor& other) {
    size = other.size;
    data = new double[size];
    ++n_instances;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DataProcessor::DataProcessor(double *data, const int size) : data(new double[size]), size(size) {
  ++n_instances;
  for (unsigned int i = 0; i < size; ++i) {
    this->data[i] = data[i];
  }
}

double DataProcessor::minimum() const{
    double min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
    
double DataProcessor::maximum() const{
    double max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

double DataProcessor::mean() const{
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

double DataProcessor::standard_deviation() const{
    double mean = this->mean();
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / size);
}

std::ostream& operator<<(std::ostream& os, const DataProcessor& dp){
    os << "DataProcessor(";
    for (int i = 0; i < dp.size; i++) {
        os << dp.data[i];
        if (i < dp.size - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

DataProcessor DataProcessor::operator+(const DataProcessor &other) const{
    if (size != other.size) {
        throw std::invalid_argument("DataProcessor::operator+: sizes do not match");
    }
    DataProcessor result(data, size);
    for (int i = 0; i < size; i++) {
        result[i] += other[i];
    }
    return result;
}

DataProcessor& DataProcessor::operator=(const DataProcessor &other){
    if (this != &other) {
    delete[] data;
    size = other.size;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = other[i];
    }
    }
    return *this;
}

double compute_correlation(const DataProcessor &dp1, const DataProcessor &dp2){
    if (dp1.n_elements() != dp2.n_elements()) {
        throw std::invalid_argument("Datasets must have the same size.");
    }
    double mean_dp1 = dp1.mean();
    double mean_dp2 = dp2.mean();

    double std_dev_dp1 = dp1.standard_deviation();
    double std_dev_dp2 = dp2.standard_deviation();

    double numerator = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;
    for (size_t i = 0; i < dp1.n_elements(); ++i) {
        double diff1 = dp1[i] - mean_dp1;
        double diff2 = dp2[i] - mean_dp2;
        numerator += diff1 * diff2;
        denom1 += diff1 * diff1;
        denom2 += diff2 * diff2;
    }

    double correlation = numerator / (std_dev_dp1 * std_dev_dp2);
    return correlation;
}