cmake_minimum_required(VERSION 3.5)
project(CAN__Access)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-fpermissive -m32")

# Set flags to build 32-bit binary & which exe to use for C / C++
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)


add_library(CAN__Access STATIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/CAN_Access.lib")
target_link_libraries(CAN__Access PRIVATE CAN_Access.lib)
target_link_directories(CAN__Access PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(CAN__Access PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

