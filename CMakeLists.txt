cmake_minimum_required(VERSION 3.30)
project(main CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

add_library(main SHARED main.cpp)
add_executable(test test.cpp)

target_include_directories(main PUBLIC "include")
target_compile_definitions(main PUBLIC XLZ_EXPORTS)

if(MSVC)
    target_link_options(main PUBLIC /LTCG /OPT:REF,ICF /DEBUG:NONE)
    target_compile_options(main PUBLIC /MT /MP /GR- /Gy)
endif()
set_target_properties(main PROPERTIES OUTPUT_NAME "XLZ")
set_target_properties(test PROPERTIES OUTPUT_NAME "Test")