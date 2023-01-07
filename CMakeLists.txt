cmake_minimum_required(VERSION 3.16)

project(OS_LABS C CXX)

enable_testing()

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra)
endif()

include(FindThreads)

find_library(LIBRT rt)

add_subdirectory(lab1)
add_subdirectory(lab2)
#add_subdirectory(lab3)
add_subdirectory(lab4)
#add_subdirectory(lab56)
add_subdirectory(another)
add_subdirectory(cp)

add_subdirectory(tests)
