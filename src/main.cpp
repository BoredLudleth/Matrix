#include <cmath>
#include <iostream>

#include "matrix.hpp"

#if defined(__has_include)
#if __has_include(<format>)
#include <format>
#define FORMAT_SUPPORT
#endif
#endif

#ifndef NDEBUG
#include <chrono>
#endif

int main() {
#ifndef NDEBUG
  auto begin = std::chrono::steady_clock::now();
#endif

  using namespace matrix_space;
  int size = 0;
  std::cin >> size;

  double* matrix_data = new double[size * size];
  for (int i = 0; i < size * size; ++i) {
    std::cin >> matrix_data[i];
  }

  matrix<double> matrix_test{size, size, matrix_data};

#ifdef FORMAT_SUPPORT
  std::cout << std::format("{}\n", round(matrix_test.det()));
#else
  std::cout << round(matrix_test.det()) << std::endl;
#endif

#ifndef NDEBUG
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
#ifdef FORMAT_SUPPORT
  std::cout << std::format("Time:{} s\n",
                           static_cast<float>(elapsed_ms.count()) / 1000);
#else
  std::cout << "Time: " << static_cast<float>(elapsed_ms.count()) / 1000
            << " s\n";
#endif
#endif

  return 0;
}