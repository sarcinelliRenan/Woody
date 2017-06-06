cmake_minimum_required(VERSION 2.8)
project(Woody)

set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(Woody ${SOURCE_FILES})
target_link_libraries(Woody ${OpenCV_LIBRARIES})