#pragma once
#include <gtest/gtest.h>

#include "matrix.hpp"

namespace matrix_space {
TEST(DetTest, MatrixTest) {
  int arr_1[9] = {1, 2, 3, 0, 0, 0, 0, 4, 3};
  int arr_2[9] = {1, 2, 3, 1, 2, 3, 0, 4, 3};
  int arr_3[9] = {1, 2, 3, 10, 4, 4, 0, 7, 9};
  int arr_4[9] = {1, 2, 3, 0, 7, 9, 10, 4, 4};

  matrix<int> matrix_1{3, 3, arr_1};
  matrix<int> matrix_2{3, 3, arr_2};
  matrix<int> matrix_3{3, 3, arr_3};
  matrix<int> matrix_4{3, 3, arr_4};
  matrix<int> matrix_5 = matrix<int>::eye(3, 3);

  EXPECT_EQ(matrix_1.det(), 0);
  EXPECT_EQ(matrix_2.det(), 0);
  EXPECT_EQ(matrix_3.det(), 38);
  EXPECT_EQ(matrix_4.det(), -38);
  EXPECT_EQ(matrix_5.det(), 1);
}

TEST(ZeroDetTest, MatrixTest) {
  int arr_1[4] = {0, 0, 0, 0};
  int arr_2[9] = {0, 0, 0, 1, 2, 3, 10, 0, -10};
  int arr_3[16] = {0, 0, 9, 1, 0, 0, 9, 2, 0, 0, 9, 3, 1, 2, 3, 4};

  matrix<int> matrix_1{2, 2, arr_1};
  matrix<int> matrix_2{3, 3, arr_2};
  matrix<int> matrix_3{4, 4, arr_3};

  EXPECT_EQ(matrix_1.det(), 0);
  EXPECT_EQ(matrix_2.det(), 0);
  EXPECT_EQ(matrix_3.det(), 0);
}
}  // namespace matrix_space