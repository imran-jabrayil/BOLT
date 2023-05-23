cmake_minimum_required(VERSION 3.25)
project(BOLT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BOLT
        callGraph.cpp
        callGraph.hpp
        cluster.cpp
        cluster.hpp
        edge.cpp
        edge.hpp
        macros.hpp
        main.cpp
        vertex.cpp
        vertex.hpp)
