cmake_minimum_required(VERSION 3.10)

project(Bricks C)

add_compile_options(-Wall -Wextra -fdiagnostics-color=always)

# 配置静态库bricks_core的文件清单
add_library(bricks_core STATIC 
            src/input.c
            src/mode.c
            src/print.c
            src/time_calc.c)

# 先跳到src的cmakelists
add_subdirectory(src)

# 编译bricks_core库时头文件到include下找,其他依赖于bricks_core的target也会继承
target_include_directories(bricks_core PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 配置安装规则
install(TARGETS bricks bricks_core
        RUNTIME DESTINATION bricks/bin
        ARCHIVE DESTINATION bricks/lib/static)