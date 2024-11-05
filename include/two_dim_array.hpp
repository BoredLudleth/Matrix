#pragma once

#include <iostream>

#if defined(__has_include)
#if __has_include(<format>)
#include <format>
#define FORMAT_SUPPORT
#endif
#endif

namespace matrix_space {
template <typename T = int>
class two_dim_array {
 protected:
  int x;
  int y;
  T** data;

 public:
  two_dim_array(int rows, int cols) : x(rows), y(cols) {
    data = new T*[x];

    for (int i = 0; i < y; ++i) {
      data[i] = new T[y];
    }
  }

  two_dim_array(two_dim_array&& rhs) noexcept {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    data = std::move(rhs.data);
  }

  ~two_dim_array() {
    for (int i = 0; i < y; ++i) {
      delete[] data[i];
    }

    delete data;
  }
};
}  // namespace matrix_space
