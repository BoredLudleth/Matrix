#pragma once
#include <gtest/gtest.h>

#include "matrix.hpp"

namespace matrix_space {

TEST(BracketsOpTest, MatrixTest) {
    int arr_1[4] = {1, 2, 3, 4};

    matrix<int> matrix_1{2, 2, arr_1};

    for (int i = 0, k = 1; i < 2; ++i) {
        for (int j = 0; j < 2; ++j, ++k) {
            EXPECT_EQ(matrix_1[i][j], k);
        }
    }

    const matrix<int> matrix_2{2, 2, arr_1};

    for (int i = 0, k = 1; i < 2; ++i) {
        for (int j = 0; j < 2; ++j, ++k) {
            EXPECT_EQ(matrix_2[i][j], k);
        }
    }
}

TEST(EyeTest, MatrixTest) {
    matrix<int> eye = matrix<int>::eye(5, 5);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == j)
                EXPECT_EQ(eye[i][j], 1);
            else
                EXPECT_EQ(eye[i][j], 0);
        }
    }
}

TEST(EqualTest, MatrixTest) {
    int arr_1[4] = {1, 0, 0, 1};
    int arr_2[4] = {1, 0, 1, 0};
    int arr_3[1] = {1};

    matrix<int> matrix_1{2, 2, arr_1};
    matrix<int> matrix_2{2, 2, arr_2};
    matrix<int> matrix_3{1, 1, arr_3};
    matrix<int> matrix_4 = matrix<int>::eye(2, 2);

    EXPECT_EQ(matrix_1 == matrix_2, 0);
    EXPECT_EQ(matrix_1 != matrix_2, 1);

    EXPECT_EQ(matrix_1 == matrix_3, 0);
    EXPECT_EQ(matrix_1 != matrix_3, 1);

    EXPECT_EQ(matrix_1 == matrix_4, 1);
    EXPECT_EQ(matrix_1 != matrix_4, 0);
}

TEST(TraceTest, MatrixTest) {
    int arr_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    matrix<int> matrix_1{3, 3, arr_1};

    EXPECT_EQ(matrix_1.trace(), 15);
}

TEST(TransposeTest, MatrixTest) {
    int arr_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    matrix<int> matrix_1{3, 3, arr_1};

    matrix_1.transpose();

    for (int i = 0, k = 1; i < 3; ++i) {
        for (int j = 0; j < 3; ++j, ++k) {
            EXPECT_EQ(matrix_1[j][i], k);
        }
    }
}

TEST(NegateTest, MatrixTest) {
    int arr_1[4] = {1, 2, 3, 4};

    matrix<int> matrix_1{2, 2, arr_1};

    matrix_1.negate();

    for (int i = 0, k = -1; i < 2; ++i) {
        for (int j = 0; j < 2; ++j, --k) {
            EXPECT_EQ(matrix_1[i][j], k);
        }
    }
}

TEST(NegateRow, MatrixTest) {
    int arr_1[4] = {-1, -2, 3, 4};

    matrix<int> matrix_1{2, 2, arr_1};
    
    matrix_1.negate_row(0);

    for (int i = 0, k = 1; i < 2; ++i) {
        for (int j = 0; j < 2; ++j, ++k) {
            EXPECT_EQ(matrix_1[i][j], k);
        }
    }

}
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
}