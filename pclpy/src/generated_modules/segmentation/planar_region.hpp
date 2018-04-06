
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

using namespace pcl;


#include <pcl/segmentation/planar_region.h>



template <typename PointT>
void defineSegmentationPlanarRegion(py::module &m, std::string const & suffix) {
    using Class = PlanarRegion<PointT>;
    py::class_<Class, Region3D<PointT>, PlanarPolygon<PointT>, boost::shared_ptr<Class>> cls(m, suffix.c_str());
    cls.def(py::init<>());
    cls.def(py::init<pcl::Region3D<PointT>, pcl::PlanarPolygon<PointT>>(), "region"_a, "polygon"_a);
    cls.def(py::init<Eigen::Vector3f, Eigen::Matrix3f, unsigned, typename pcl::PointCloud<PointT>::VectorType, Eigen::Vector4f>(), "centroid"_a, "covariance"_a, "count"_a, "contour"_a, "coefficients"_a);
        
}

void defineSegmentationPlanarRegionClasses(py::module &sub_module) {
}