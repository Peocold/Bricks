add_executable(bricks main.c)

set_target_properties(bricks PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_link_libraries(bricks bricks_core)