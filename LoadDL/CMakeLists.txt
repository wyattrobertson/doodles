
cmake_minimum_required(VERSION 3.5)

project(LoadDL)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#==========================================================
# Create dynamic libraries
#==========================================================

# Create dynamic library
add_library(function SHARED
    function.cpp
)

target_include_directories(function
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/function.hpp
)


#==========================================================
# Create executable
#==========================================================

# Create executable
add_executable(main.out
   main.cpp
)

# Link libdl.so for UNIX .so utilities
find_library(DL_LIBRARY libdl.so)

target_link_libraries(main.out
    ${DL_LIBRARY}
)

target_include_directories(main.out
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/dl.hpp
)
