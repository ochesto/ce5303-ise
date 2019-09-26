#define minumum CMake version
cmake_minimum_required (VERSION 2.6)

#define the project name
project (hello)

#add executable to build environment
add_executable(hello hello-world.c)

#copy executable to bin directory
install (TARGETS hello DESTINATION bin)