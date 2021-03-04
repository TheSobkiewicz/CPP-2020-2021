cmake_minimum_required (VERSION 2.6)
project (Lab12 CXX)

add_executable(Lab12 main.cpp)

set(LIBSRC include/MyNode.h src/MyNode.cpp include/MyList.h src/MyList.cpp )
add_library(lab12 ${LIBSRC})

target_link_libraries(Lab12 lab12)
include_directories(include)
include_directories(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall -DCMAKE_CXX_COMPILER=clang++")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab12 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab12
    DEPENDS Lab12
)