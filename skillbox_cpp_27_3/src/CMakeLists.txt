cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Skillbox_cpp_27_3 main.cpp Employee.cpp Task.cpp Inputs.cpp)

target_include_directories(Skillbox_cpp_27_3 PUBLIC ${MY_INCLUDE})