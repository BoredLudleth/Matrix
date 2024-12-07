find_package(GTest REQUIRED)

include_directories(${INCLUDE_DIR})

add_executable(matrix_test matrix_test.cpp)

target_link_libraries(matrix_test GTest::gtest_main)

add_test(matrix_gtest matrix_test)

add_custom_command(TARGET matrix_test
                   COMMENT "Run tests"
                   POST_BUILD 
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   COMMAND ${CMAKE_CTEST_COMMAND})

add_test(NAME matrix_end2end
         COMMAND ${CMAKE_COMMAND} -E echo "Запуск e2e тестов..." && bash ${CMAKE_CURRENT_SOURCE_DIR}/run_e2e_tests.sh)
