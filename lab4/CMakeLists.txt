project(nameserver)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(nsvector nsvector.cpp nstest.cpp split.cpp stopwatch.cpp)
target_compile_options(nsvector PRIVATE -O3 -std=c++20)

add_executable(nsmap nsmap.cpp nstest.cpp split.cpp stopwatch.cpp)
target_compile_options(nsvector PRIVATE -O3 -std=c++20)

add_executable(nsumap nsumap.cpp nstest.cpp split.cpp stopwatch.cpp)
target_compile_options(nsvector PRIVATE -O3 -std=c++20)
