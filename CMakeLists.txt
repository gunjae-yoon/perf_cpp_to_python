cmake_minimum_required(VERSION 3.8)
project(ctopy CXX)

set(pybind11_DIR "/home/gunjae/.local/lib/python3.10/site-packages/pybind11/share/cmake/pybind11")

find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
set(PYBIND11_PYTHON_VERSION 3.6)


include_directories(
	include
	src
)

add_library(ctopy SHARED 
	src/ctopy/ctopy.cpp
)

pybind11_add_module(pybind
	src/ctopy/ctopy.cpp
	src/ctopy/pybind.cpp
)

target_include_directories(pybind PRIVATE ${PYBIND11_INCLUDE_DIRS})
