cmake_minimum_required(VERSION 3.11) 
project(L10T2) 

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()


set (SOURCES 
   main.cpp
q.cpp
fig.cpp
r.cpp

)

set (HEADERS 
q.h
fig.h
r.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

