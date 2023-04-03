cmake_minimum_required(VERSION 2.9.3)
project(performance_test)

find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)

add_compile_options(-O3)

add_compile_options(-Wall)
add_compile_options(-Werror=unused)
add_compile_options(-Werror=address)
add_compile_options(-Werror=return-type)
add_compile_options(-Werror=uninitialized)
add_compile_options(-Werror=unused-parameter)
add_compile_options(-Werror=dangling-else)
add_compile_options(-Wsign-compare)
add_compile_options(-Wno-reorder)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Werror=unused-private-field)
  add_compile_options(-Wthread-safety)
endif()

include_directories(include ${EIGEN3_INCLUDE_DIRS})

file(GLOB SRC_FILES src/main.cpp 
                    src/stddev_unittest.cpp
                    src/float_comparison_unittest.cpp
                    src/float_arithmetic_unittest.cpp
                    src/eigen_matrix_unittest.cpp )

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest)
