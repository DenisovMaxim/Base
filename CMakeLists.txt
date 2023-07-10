cmake_minimum_required(VERSION 3.5)

project(Base)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC include/${PROJECT_NAME}/*.h )
add_library(${PROJECT_NAME} INTERFACE ${SRC})

target_include_directories(${PROJECT_NAME} INTERFACE include/)

include("unittest.cmake")