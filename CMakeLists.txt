cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

set(PROJECT_NAME_HASHMAP "HASHMAP")
if (UNIX)
    set(PROJECT_NAME_HASHMAP "${PROJECT_NAME_HASHMAP}.exe")
endif()

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME_HASHMAP} HashMaps/hashmap.c)
set_target_properties(${PROJECT_NAME_HASHMAP} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
target_compile_options(${PROJECT_NAME_HASHMAP} PRIVATE -Wall -Wextra -Wpedantic -Werror)
