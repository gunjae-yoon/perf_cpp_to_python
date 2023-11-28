cmake_minimum_required(VERSION 3.8)
project(ctopy CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

include_directories(
	include
	src
)

set(LIB_SRC
	src/ctopy/ctopy.cpp
)

add_library(ctopy SHARED ${LIB_SRC})
