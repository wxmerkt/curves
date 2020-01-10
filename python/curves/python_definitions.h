#include "curves/fwd.h"
#include "curves/bezier_curve.h"
#include "curves/linear_variable.h"
#include "curves/quadratic_variable.h"

#include <vector>

#ifndef _DEFINITION_PYTHON_BINDINGS
#define _DEFINITION_PYTHON_BINDINGS

namespace curves {
/*** TEMPLATE SPECIALIZATION FOR PYTHON ****/
typedef double real;
typedef std::vector<real> t_time_t;
typedef Eigen::VectorXd time_waypoints_t;

typedef Eigen::Matrix<double, Eigen::Dynamic, 1, 0, Eigen::Dynamic, 1> ret_pointX_t;
typedef std::pair<pointX_t, pointX_t> pair_pointX_tangent_t;
typedef Eigen::MatrixXd pointX_list_t;
typedef std::vector<pair_pointX_tangent_t, Eigen::aligned_allocator<pair_pointX_tangent_t> > t_pair_pointX_tangent_t;
typedef curves::curve_constraints<pointX_t> curve_constraints_t;
typedef curves::curve_constraints<point3_t> curve_constraints3_t;
typedef std::pair<real, pointX_t> waypoint_t;
typedef std::vector<waypoint_t> t_waypoint_t;
typedef Eigen::Matrix<real, Eigen::Dynamic, Eigen::Dynamic> point_listX_t;
typedef Eigen::Matrix<real, 3, Eigen::Dynamic> point_list3_t;
typedef Eigen::Matrix<real, 6, Eigen::Dynamic> point_list6_t;

typedef polynomial_t::coeff_t coeff_t;
typedef curves::Bern<double> bernstein_t;

template <typename PointList, typename T_Point>
T_Point vectorFromEigenArray(const PointList& array) {
  T_Point res;
  for (int i = 0; i < array.cols(); ++i) {
    res.push_back(array.col(i));
  }
  return res;
}
template <typename PointList, typename T_Point>
T_Point vectorFromEigenVector(const PointList& vector) {
  T_Point res;
  for (int i = 0; i < vector.rows(); ++i) {
    res.push_back(vector[i]);
  }
  return res;
}
}  // namespace curves
#endif  //_DEFINITION_PYTHON_BINDINGS
