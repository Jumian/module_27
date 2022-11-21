cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
add_executable(Skillbox_cpp_27_2 main.cpp Figure.cpp Coords.cpp)

target_include_directories(Skillbox_cpp_27_2 PUBLIC ${MY_INCLUDE})