add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(all_tests_run
        ../Customer.cpp
        ../Customer.h
        CustomerTests.cpp)

target_link_libraries(all_tests_run
        gtest
        gtest_main)