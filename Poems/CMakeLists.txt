cmake_minimum_required (VERSION 2.6)
project (Lab08 CXX)

include_directories(include src)

add_executable(Lab08 main.cpp)

set(LIBSRC include/MyPoem.h  src/MyPoem.cpp
include/MyLine.h  src/MyLine.cpp )
add_library(lab08 ${LIBSRC})

target_link_libraries(Lab08 lab08)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab08 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab08
    DEPENDS Lab08
)