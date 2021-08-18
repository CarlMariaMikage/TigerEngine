cmake_minimum_required(VERSION 3.20.5)
project(TigerEngine VERSION 0.0)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -O2") #use C++17 and maximum optimisation
set(GCC_COVERAGE_LINK_FLAGS "-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl") #required libraries for GLFW

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}") #set compiler flags
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}") #set linker flags

include_directories(include) #include directories
file(GLOB SOURCES "src/*.cpp" "src/*.c") #source directories

add_executable(engine ${SOURCES})