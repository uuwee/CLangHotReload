cmake_minimum_required(VERSION 3.26)
project(lib-test C CXX)

file(GLOB_RECURSE lib_src "lib/*.c")

add_library(lib-test SHARED  ${lib_src})
target_include_directories(
  lib-test PUBLIC "lib"
)
add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
target_compile_definitions(lib-test PRIVATE LIB_EXPORT)


# samples
file(GLOB_RECURSE example_src "./example/*.c")
add_executable(example ${example_src})
target_include_directories(example PUBLIC "./example" "./lib" )
add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
