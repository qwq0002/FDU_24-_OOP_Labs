project(ackermann)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})

add_executable(E211 E211.cc)
target_compile_options(E211 PRIVATE -std=c++20)

add_executable(E212 E212.cc)
target_compile_options(E212 PRIVATE -std=c++20)

add_executable(E213 E213.cc)
target_compile_options(E213 PRIVATE -std=c++20)

add_executable(grid grid.cc grid_main.cc)
target_compile_options(grid PRIVATE -std=c++20)
