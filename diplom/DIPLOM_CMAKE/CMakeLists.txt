#минимальная версия cmake на котором будет работать 
cmake_minimum_required(VERSION 3.11) 
#название проекта и как следствие солюшена в студии 
project(race) 
#Для студии ставим флаг, что кодировка исходников UTF-8
if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()
#делаем всё экспортируемым
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#добавляем запускаемый файл с именем проекта 
add_executable(race kursovik.cpp) 
#добавляем библиотеку транспортов
add_library(transport SHARED racers.h racers.cpp) 
#линкуем библиотеки 
target_link_libraries(race PRIVATE transport)