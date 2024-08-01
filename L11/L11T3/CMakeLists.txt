cmake_minimum_required(VERSION 3.11) 
project(L11T3) 
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)  # export all symbols from outside

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_executable(L11T3 l11t3.cpp)

add_library(leaver SHARED
    leaver.h
   leaver.cpp)
   
target_link_libraries(L11T3 leaver)   