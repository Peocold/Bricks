cmake_minimum_required(VERSION 3.10)

project(Bricks C)

add_compile_options(-Wall -Wextra -fdiagnostics-color=always)

add_library(bricks_core STATIC 
            src/input.c
            src/mode.c
            src/print.c
            src/time_calc.c)

add_subdirectory(src)

target_include_directories(bricks_core PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(TARGETS bricks bricks_core
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib/static)