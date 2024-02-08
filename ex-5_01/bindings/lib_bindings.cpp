#include <pybind11/pybind11.h>
#include "../lib/calculator.hpp"
#include <stdexcept>

namespace py = pybind11;

PYBIND11_MODULE(exam_lib, m) { 

    py::class_<Calculator>(m, "Calculator")
        .def(py::init<>())
        .def("add", &Calculator::add)
        .def("subtract", &Calculator::subtract)
        .def("multiply", &Calculator::multiply)
        .def("divide", [](Calculator &self, const double &a, const double &b) {
            try {
                return self.divide(a, b);
            } catch (const std::invalid_argument& e) {
                throw py::value_error(e.what());
            }    
        });
}