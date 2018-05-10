
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include "io/hdl_grabber.hpp"
#include "io/ifs_io.hpp"


void defineIoClasses2(py::module &m) {
    py::module m_io = m.def_submodule("io", "Submodule io");
    defineIoHdlGrabberClasses(m_io);
    defineIoIfsIoClasses(m_io);
}