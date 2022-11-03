set (CMAKE_C_STANDART 11)

add_executable(lab2 main.c src/lab2.c)

target_include_directories(lab2 PRIVATE include)

target_link_libraries(lab2 PRIVATE Threads::Threads)
