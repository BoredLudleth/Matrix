#include <fstream>
#include <iostream>
#include <random>

#include "matrix.hpp"

int main() {
  using namespace matrix_space;

  int N = 0, size = 0;

  std::cout << "Which determinant do you want? ";
  std::cin >> N;

  std::cout << "Size of the matrix? ";
  std::cin >> size;

  std::mt19937 rng(std::random_device{}());

  matrix<int> result = matrix<int>::eye(size, size);
  result[0][0] = N;

  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      result[i][j] = rand() % 10;
    }
  }

  for (int i = 0; i < 100; ++i) {
    int command = rand() % 10;

    if (command == 0) {
      result.transpose();
      continue;
    }

    if (command % 2 == 0) {
      result.add_rows(rand() % size, rand() % size);
      continue;
    }

    result.sub_rows(rand() % size, rand() % size);
    continue;
  }

  std::ofstream out;
  out.open("test.dat");
  if (out.is_open()) {
    result.dump(out);
  } else {
    std::cout << "File didn't wroten\n";
  }

  out << std::endl;
  out.close();
}