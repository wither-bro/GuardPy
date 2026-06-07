cmake_minimum_required(VERSION 3.10)
project(GuardPy C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES 
    "*.cpp" "*.c" "*.h" "*.hpp"
    "App/**/*.cpp" 
    "App/**/*.c"
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(GuardPy ${SOURCES})

target_link_libraries(GuardPy sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET GuardPy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    "${CMAKE_SOURCE_DIR}/Assets" 
    "$<TARGET_FILE_DIR:GuardPy>/Assets"
)
