cmake_minimum_required(VERSION 3.9)
project(sptucker)
include_directories("include/")
set(SRCS
        src/def.cpp
        src/read_data.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SRCS})