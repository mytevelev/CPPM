cmake_minimum_required(VERSION 3.11) 
project(L10T1) 

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_executable(L10T1 main.cpp)
