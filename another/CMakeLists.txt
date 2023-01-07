set(CMAKE_C_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)

add_executable(another main.c src/parent_lab3.c)
add_executable(child1_another src/child1_lab3.c)
add_executable(child2_another src/child2_lab3.c)

target_link_libraries(another PRIVATE Threads::Threads)
target_link_libraries(child1_another PRIVATE Threads::Threads)
target_link_libraries(child2_another PRIVATE Threads::Threads)

add_dependencies(another child1_another child2_another)