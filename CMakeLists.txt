cmake_minimum_required(VERSION 3.5)

project(Base)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(UNITTEST ON)
add_library(Base INTERFACE complex.h signalFile.h reader.h writer.h demod.h)

if(UNITTEST)
        add_subdirectory(googletests/)
        include("unittest.cmake")
endif()
