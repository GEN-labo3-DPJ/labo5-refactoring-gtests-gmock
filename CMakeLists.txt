cmake_minimum_required(VERSION 3.15)
project(labo5_refactoring_gtests_gmock)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)

add_executable(main
        main.cpp
        Customer.cpp
        Customer.h
        Movie.cpp
        Movie.h
        Rental.h)