#include <cmath>
#include <format>
#include <iostream>

#include "matrix.hpp"

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

  float* matrix_data = new float[size * size];
  for (int i = 0; i < size * size; ++i) {
    std::cin >> matrix_data[i];
  }

  matrix<float> matrix_test{size, size, matrix_data};

#ifdef FORMAT_SUPPORT
  std::cout << std::format("{}\n", matrix_test.det());
#else
  float* ans = new float;
  std::modf(matrix_test.det(), ans);
  std::cout.setf(std::ios_base::fixed);
  std::cout << *ans << std::endl;
  delete ans;
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