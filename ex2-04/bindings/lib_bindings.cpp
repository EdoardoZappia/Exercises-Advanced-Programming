#include <pybind11/pybind11.h>
#include "../lib/datasource.hpp"
#include "../lib/filedatasource.hpp"
#include "../lib/consoledatasource.hpp"
#include "../lib/datatransformer.hpp"
#include "../lib/linearscaler.hpp"
#include "../lib/standardscaler.hpp"
#include "../lib/logtransformer.hpp"



namespace py = pybind11;

PYBIND11_MODULE(datasource, m) {
    
    py::class_<DataSource>(m, "DataSource")
        //.def(py::init<const std::string>())   DataSource is a virtual class, so it cannot be instantiated
        //.def(py::init<const std::string, std::vector<double>>())

        .def("read_data", &DataSource::read_data)
        //.def("__str__", &DataSource::display_info);
        .def("__str__", [](DataSource &ds) {
            ds.display_info();
            return "";
        });

    py::class_<FileDataSource, DataSource>(m, "FileDataSource")
        .def(py::init<const std::string>())
        .def("destroy",[](FileDataSource &self) { self.~FileDataSource(); })
        .def("read_data", &FileDataSource::read_data);
    
    py::class_<ConsoleDataSource, DataSource>(m, "ConsoleDataSource")
        .def(py::init<>())
        .def("read_data", &ConsoleDataSource::read_data);
    
    py::class_<DataTransformer>(m, "DataTransformer")
        //.def(py::init<DataSource *>()) DataTransformer is a virtual class, so it cannot be instantiated
        .def("transform", &DataTransformer::transform);
    
    py::class_<LinearScaler, DataTransformer>(m, "LinearScaler")
        .def(py::init<DataSource *, double>())
        .def("transform", &LinearScaler::transform);

    py::class_<StandardScaler, DataTransformer>(m, "StandardScaler")
        .def(py::init<DataSource *>())
        .def("transform", &StandardScaler::transform);

    py::class_<LogTransformer, DataTransformer>(m, "LogTransformer")
        .def(py::init<DataSource *>())
        .def("transform", &LogTransformer::transform);
}