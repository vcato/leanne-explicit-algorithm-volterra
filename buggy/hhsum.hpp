// hhsum.hpp
#ifndef HHSUM_HPP // include guard
#define HHSUM_HPP

#include <string>

namespace hhsum {
  double series(int n, double t);

  double findError(double h1,double h2);

  double
    beta(
      int n,
      int r,
      double k,
      double t,
      double theta,
      double c,
      double sig,
      double del,
      std:: string& base
    );

  void norms(double* x, int n, double& norm1, double& norminf);
};

#endif
