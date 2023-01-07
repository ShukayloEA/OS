set(CMAKE_CXX_STANDARD 14)

add_executable(cp main.cpp src/ListAllocator.cpp src/N2Allocator.cpp)
target_include_directories(cp PRIVATE include)
