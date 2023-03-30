cmake_minimum_required(VERSION 3.22)
project(Code)

set(CMAKE_CXX_STANDARD 23)

add_executable(Code main.cpp vectorDinamic.cpp vectorDinamic.h tests.cpp tests.h iteratorVectorDinamic.cpp iteratorVectorDinamic.h)
