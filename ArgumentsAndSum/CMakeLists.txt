cmake_minimum_required (VERSION 2.6)

project (Lab)

include_directories(include src)
add_executable(Lab main.cpp)

set(LIBSRC include/ src/Argumenty.cpp)

add_library(lab08 ${LIBSRC})
set_target_properties(lab08 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Lab lab08)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
