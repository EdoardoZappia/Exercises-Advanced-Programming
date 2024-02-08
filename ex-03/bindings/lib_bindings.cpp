#include <pybind11/pybind11.h>
#include "../lib/dataprocessor.hpp"
#include <sstream>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(exam_lib, m) {   
    
    py::class_<DataProcessor>(m, "DataProcessor")
        .def(py::init([](std::vector<double> &data, const int size) {
            return new DataProcessor(data.data(), size);
        }))
        .def(py::init<const DataProcessor&>())  
        .def("n_elements", &DataProcessor::n_elements)
        .def("minimum", &DataProcessor::minimum)
        .def("maximum", &DataProcessor::maximum)
        .def("mean", &DataProcessor::mean)
        .def("standard_deviation", &DataProcessor::standard_deviation)
        .def("get_n_instances", &DataProcessor::get_n_instances)
        .def("__setitem__", [](DataProcessor &dp, unsigned int index, double value){return dp[index]=value;}) 
        .def("__getitem__", py::overload_cast<const int>(&DataProcessor::operator[], py::const_))
        .def("__add__", &DataProcessor::operator+)
        .def("__repr__", [](const DataProcessor &dp) {
            std::ostringstream oss;
            oss << "DataProcessor(";
            for (int i = 0; i < dp.n_elements(); i++) {
                oss << dp[i];
                if (i < dp.n_elements() - 1) {
                    oss << ", ";
                }
            }
            oss << ")";
            return oss.str();
        });
    m.def("compute_correlation", &compute_correlation);
}