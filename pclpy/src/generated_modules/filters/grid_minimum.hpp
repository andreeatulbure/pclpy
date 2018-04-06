
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

using namespace pcl;


#include <pcl/filters/grid_minimum.h>



template <typename PointT>
void defineFiltersGridMinimum(py::module &m, std::string const & suffix) {
    using Class = GridMinimum<PointT>;
    py::class_<Class, FilterIndices<PointT>, boost::shared_ptr<Class>> cls(m, suffix.c_str());
    cls.def(py::init<float>(), "resolution"_a);
    cls.def_property("resolution", &Class::getResolution, &Class::setResolution);
        
}

void defineFiltersGridMinimumClasses(py::module &sub_module) {
    py::module sub_module_GridMinimum = sub_module.def_submodule("GridMinimum", "Submodule GridMinimum");
    defineFiltersGridMinimum<InterestPoint>(sub_module_GridMinimum, "InterestPoint");
    defineFiltersGridMinimum<PointDEM>(sub_module_GridMinimum, "PointDEM");
    defineFiltersGridMinimum<PointNormal>(sub_module_GridMinimum, "PointNormal");
    defineFiltersGridMinimum<PointSurfel>(sub_module_GridMinimum, "PointSurfel");
    defineFiltersGridMinimum<PointWithRange>(sub_module_GridMinimum, "PointWithRange");
    defineFiltersGridMinimum<PointWithScale>(sub_module_GridMinimum, "PointWithScale");
    defineFiltersGridMinimum<PointWithViewpoint>(sub_module_GridMinimum, "PointWithViewpoint");
    defineFiltersGridMinimum<PointXYZ>(sub_module_GridMinimum, "PointXYZ");
    defineFiltersGridMinimum<PointXYZHSV>(sub_module_GridMinimum, "PointXYZHSV");
    defineFiltersGridMinimum<PointXYZI>(sub_module_GridMinimum, "PointXYZI");
    defineFiltersGridMinimum<PointXYZINormal>(sub_module_GridMinimum, "PointXYZINormal");
    defineFiltersGridMinimum<PointXYZL>(sub_module_GridMinimum, "PointXYZL");
    defineFiltersGridMinimum<PointXYZLNormal>(sub_module_GridMinimum, "PointXYZLNormal");
    defineFiltersGridMinimum<PointXYZRGB>(sub_module_GridMinimum, "PointXYZRGB");
    defineFiltersGridMinimum<PointXYZRGBA>(sub_module_GridMinimum, "PointXYZRGBA");
    defineFiltersGridMinimum<PointXYZRGBL>(sub_module_GridMinimum, "PointXYZRGBL");
    defineFiltersGridMinimum<PointXYZRGBNormal>(sub_module_GridMinimum, "PointXYZRGBNormal");
}