cmake_minimum_required(VERSION 3.25)

project(lab5)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main year.cpp year_main.cpp)

# add gtest lib for testing
enable_testing()
include(FetchContent)
FetchContent_Declare(
    GTest
    VERSION v1.14.0
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(GTest)

add_executable(year_test year.cpp year_test.cpp)
target_link_libraries(year_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
