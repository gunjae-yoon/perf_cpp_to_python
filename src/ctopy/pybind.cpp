#include <ctopy/ctopy.h>
#include <pybind11/pybind11.h>

using namespace ctopy;
namespace py = pybind11;

PYBIND11_MODULE(pybind, m) {
	m.doc() = "CToPy module using PyBind11";
	m.def("access", &Access);
	m.def("start", &Start);
	m.def("end", &End);
	m.def("get_elapsed_time", &GetElapsedTime);
	m.def("get_elapsed_time_per_access", &GetElapsedTimePerAccess);
}
