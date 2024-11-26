#pragma once
#include <gtest/gtest.h>
#include <cmath>

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

TEST(MinusEyeTest, MatrixTest) {
  int arr_1[4] = {-1, 0, 0, 1};
  int arr_2[9] = {1, 0, 0, 0, 0, 1, 0, 1, 0};
  int arr_3[16] = {0, 0, 0, -1, 0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 0, 0};

  matrix<int> matrix_1{2, 2, arr_1};
  matrix<int> matrix_2{3, 3, arr_2};
  matrix<int> matrix_3{4, 4, arr_3};

  EXPECT_EQ(matrix_1.det(), -1);
  EXPECT_EQ(matrix_2.det(), -1);
  EXPECT_EQ(matrix_3.det(), 1);
}

TEST(RandomDetTest, MatrixTest) {
  int arr_1[4] = {1, 4, -5, 7};
  int arr_2[9] = {5, 3, 4, 1, 2, 13, 3, 3, 18};
  int arr_3[16] = {4, 7, 2, 3, 1, 3, 1, 2, 2, 5, 3, 4, 1, 4, 2, 3};

  matrix<int> matrix_1{2, 2, arr_1};
  matrix<int> matrix_2{3, 3, arr_2};
  matrix<int> matrix_3{4, 4, arr_3};

  EXPECT_EQ(matrix_1.det(), 27);
  EXPECT_EQ(matrix_2.det(), 36);
  EXPECT_EQ(matrix_3.det(), -3);
}
TEST(SignProblemTest, MatrixTest) {
  int arr_1[9] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
  matrix<int> matrix_1{3, 3, arr_1};

  EXPECT_EQ(matrix_1.det(), -1);
}

TEST(RoundProblemTest, MatrixTest) {
  double arr_1[25] = {70, 753, 1077, 823, 19, 81, 402, 526, 460, 24, 
                   -16, -184, -263, -198, -5, -105, -961, -1363, -1068, -27, 
                   -120, -601, -784, -682, -36};
  
  matrix<double> matrix_1{5, 5, arr_1};

  EXPECT_EQ(round(matrix_1.det()), 88);
}
}  // namespace matrix_space