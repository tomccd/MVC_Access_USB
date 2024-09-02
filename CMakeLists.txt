cmake_minimum_required(VERSION 3.5)
project(MVC_USB)

add_library(
    MVC_Architecture SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MVC_Architecture.cpp
)

target_link_libraries(
    MVC_Architecture
    stdc++fs
)

add_executable(
    main
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/header/MVC_Architecture.hpp
)

target_link_libraries(
    main
    MVC_Architecture
)