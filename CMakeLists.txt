cmake_minimum_required(VERSION 3.28)
project(Blocks2d VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

add_executable(Blocks2d ${PROJECT_SOURCES})

target_include_directories(Blocks2d PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Blocks2d PRIVATE sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET Blocks2d POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/res"
    "$<TARGET_FILE_DIR:Blocks2d>/res"
    COMMENT "Copying resources to build directory..."
)
