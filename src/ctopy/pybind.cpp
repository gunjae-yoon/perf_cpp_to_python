#include <ctopy/ctopy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pybind, m) {
	m.doc() = "CToPy module using PyBind11";
	m.def("access", &c_access);
	m.def("start", &c_start);
	m.def("end", &c_end);
	m.def("get_elapsed_time", &c_get_elapsed_time);
	m.def("get_elapsed_time_per_access", &c_get_elapsed_time_per_access);
}
