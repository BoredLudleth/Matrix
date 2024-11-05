cmake_minimum_required(VERSION 3.0)

project(matrix)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTING "Build tests" ON)


include_directories(${INCLUDE_DIR})

add_executable (matrix src/main.cpp)

add_executable(matrix_gen src/matrix_gen.cpp)

if(BUILD_TESTING)
  include(CTest)
  enable_testing()
  add_subdirectory(test/)
endif()