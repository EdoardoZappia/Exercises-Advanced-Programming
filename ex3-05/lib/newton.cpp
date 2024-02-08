#include "newton.hpp"
#include <cmath>
#include <limits>
#include <functional>

template <typename T>
NewtonSolver<T>::NewtonSolver(const std::function<T(const T &)> &f,
                              const std::function<T(const T &)> &df,
                              const T &x0, const double &tolerance,
                              const unsigned int &max_iterations)
        : f(f), df(df), x0(x0), tolerance(tolerance),
            max_iterations(max_iterations) {}

template <typename T>
T NewtonSolver<T>::solve() {
    T x = x0;

  unsigned int it = 0;

  while (it < max_iterations) {
    const T delta = f(x) / df(x);
    x -= delta;

    if (std::abs(delta) < tolerance) {
      return x;
    }

    ++it;
  }

  throw std::runtime_error("NewtonSolver failed to converge to a root.");

  return T();
}


template class NewtonSolver<double>;
template class NewtonSolver<std::complex<double>>;
