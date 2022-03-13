cmake_minimum_required(VERSION 3.9)
project(sptucker)
include_directories("include/")
set(SRCS
        src/def.cpp
        src/read_data.cpp
        src/sptensor.cpp)
set(INCLUDES
        include/def.hpp
        include/read_data.hpp
        include/sptensor.hpp)

set(CMAKE_CXX_FLAGS "-fopenmp -O3 -Wall")
add_executable(${PROJECT_NAME} main.cpp ${SRCS})