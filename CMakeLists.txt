cmake_minimum_required(VERSION 3.16)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(GA-TSP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(SOURCES src/main.cpp 
            src/graph.cpp 
            src/population.cpp 
            src/specimen.cpp 
            src/params.cpp 
            src/genetic_algorithm.cpp)

add_executable(GA-TSP ${SOURCES})

target_link_libraries(GA-TSP /usr/local/lib/libutility.a)
