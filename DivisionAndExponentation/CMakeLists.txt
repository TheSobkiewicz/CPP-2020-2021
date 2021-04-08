cmake_minimum_required (VERSION 2.6)

project (Lab)

include_directories(include src)
add_executable(Lab main.cpp)

set(LIBSRC include/Division.h include/Exponentiation.h include/Operation.h include/SumOfElements.h src/Division.cpp src/Exponentiation.cpp src/SumOfElements.cpp src/Operation.cpp)

add_library(lab ${LIBSRC})
set_target_properties(lab PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Lab lab)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall -g")