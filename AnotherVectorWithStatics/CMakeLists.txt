cmake_minimum_required (VERSION 2.6)

project (Lab02)

include_directories(include src)
add_executable(Lab02 main.cpp)

set(LIBSRC include/W.h src/W.cpp)

add_library(lab02 ${LIBSRC})
set_target_properties(lab02 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Lab02 lab02)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")