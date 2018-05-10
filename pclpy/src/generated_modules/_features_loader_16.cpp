
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include "features/grsd.hpp"
#include "features/shot.hpp"


void defineFeaturesClasses16(py::module &m) {
    py::module m_features = m.def_submodule("features", "Submodule features");
    defineFeaturesGrsdClasses(m_features);
    defineFeaturesShotClasses(m_features);
}