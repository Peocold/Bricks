add_executable(bricks main.c)

# 将bricks的编译后得到的可执行文件放到build目录
set_target_properties(bricks PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 把静态库bricks_core链接到bricks.o
target_link_libraries(bricks PRIVATE bricks_core)