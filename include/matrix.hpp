#pragma once
#include "two_dim_array.hpp"

namespace matrix_space {
template <typename T = int>
class matrix final : private two_dim_array<T> {
 private:
  using two_dim_array<T>::data;
  using two_dim_array<T>::x;
  using two_dim_array<T>::y;

  struct proxy_row {
    T* row;

    T& operator[](int n) { return row[n]; }

    const T& operator[](int n) const { return row[n]; }
  };

 public:
  static matrix eye(int rows, int cols) {
    matrix result = matrix<T>{rows, cols, 0};
    for (int k = 0; k < rows; ++k) {
      result.data[k][k] = 1;
    }
    return result;
  }

  matrix(int rows, int cols, T* value) : two_dim_array<T>{rows, cols} {
    for (int i = 0, k = 0; i < x; ++i) {
      for (int j = 0; j < x; ++j, ++k) {
        data[i][j] = value[k];
      }
    }
  }
  matrix(int rows, int cols, T value = T{}) : two_dim_array<T>{rows, cols} {
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        data[i][j] = value;
      }
    }
  }

  matrix(const matrix& rhs) : two_dim_array<T>{rhs.nrows(), rhs.ncols()} {
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        data[i][j] = rhs.data[i][j];
      }
    }
  }

  matrix(matrix&& rhs) noexcept = default;

  matrix& operator=(matrix&& rhs) noexcept {
    data = std::move(rhs.data);
    x = std::move(rhs.x);
    y = std::move(rhs.y);
  }  // move

  matrix& operator=(const matrix& rhs) {
    matrix tmp{rhs};
    std::swap(*this, tmp);
  }  // copy

  int nrows() const { return x; }

  int ncols() const { return y; }

  T trace() const {
    T result = 0;

    for (int i = 0; i < std::min(x, y); ++i) {
      result += data[i][i];
    }

    return result;
  }

  void dump(std::ostream& os) const {
#ifdef FORMAT_SUPPORT
    os << std::format("{}\n", x);
#else
    os << x << "\n";
#endif
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
#ifdef FORMAT_SUPPORT
        os << std::format("{} ", data[i][j]);
#else
        os << data[i][j] << " ";
#endif
      }
      os << "\n";
    }
    os << "\n";
  }

  matrix& negate_row(int i) & {
    for (int j = 0; j < y; ++j) {
      data[i][j] *= -1;
    }

    return *this;
  }

  matrix& negate() & {
    for (int i = 0; i < x; ++i) {
      negate_row(i);
    }

    return *this;
  }

  matrix& transpose() & {
    for (int i = 0; i < x; ++i) {
      for (int j = i + 1; j < x; ++j) {
        std::swap(data[i][j], data[j][i]);
      }
    }

    return *this;
  }

  void swap_rows(int i, int j) {
    if (i == j) return;

    negate_row(i);

    std::swap(data[i], data[j]);
  }

  void add_rows(int first, int second) {
    if (first != second) {
      for (int i = 0; i < y; ++i) {
        data[first][i] += data[second][i];
      }
    }
  }

  void sub_rows(int first, int second) {
    if (first != second) {
      for (int i = 0; i < x; ++i) {
        data[first][i] -= data[second][i];
      }
    }
  }

  T det() const {
    matrix tmp = {*this};

    for (int k = 0; k < x - 1; ++k) {
      // need to add swaps with lower
      if (tmp[k][k] == 0) {
        int i = 0;
        for (i = k + 1; i < x; ++i) {
          if (tmp[i][k] != 0) {
            tmp.swap_rows(k, i);
            break;
          }
        }

        if (i == x) return 0;
      }

      for (int i = k + 1; i < x; ++i) {
        for (int j = k + 1; j < x; ++j) {
          if (k > 0)
            tmp[i][j] = (tmp[i][j] * tmp[k][k] - tmp[i][k] * tmp[k][j]) /
                        tmp[k - 1][k - 1];
          else
            tmp[i][j] = (tmp[i][j] * tmp[k][k] - tmp[i][k] * tmp[k][j]);
        }
      }
    }
    return tmp[x - 1][x - 1];
  }

  bool operator==(const matrix& other) const {
    if (this == &other) return true;

    if (x != other.nrows()) return false;

    if (y != other.ncols()) return false;

    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        if (data[i][j] != other[i][j]) return false;
      }
    }

    return true;
  }

  bool operator!=(const matrix& other) const { return !operator==(other); }

  proxy_row operator[](int n) {
    proxy_row temp{*(data + n)};

    return temp;
  }

  const proxy_row operator[](int n) const {
    proxy_row temp{*(data + n)};

    return temp;
  }
};
}  // namespace matrix_space
