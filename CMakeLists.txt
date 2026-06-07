cmake_minimum_required(VERSION 3.10)
project(GuardPy C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/exe")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/exe")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/exe")

file(GLOB_RECURSE SOURCES 
    "*.cpp" "*.c"
    "App/**/*.cpp" 
    "App/**/*.c"
    "DataBase/**/*.cpp"
    "DataBase/**/*.c"
    "Online/**/*.cpp"
    "Online/**/*.c"
)

list(FILTER SOURCES EXCLUDE REGEX "/build/")
list(FILTER SOURCES EXCLUDE REGEX "/build-win/")
list(FILTER SOURCES EXCLUDE REGEX "/sfml-windows/")
list(FILTER SOURCES EXCLUDE REGEX "/CMakeFiles/")
list(FILTER SOURCES EXCLUDE REGEX "/\.git/")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(GuardPy ${SOURCES})

target_link_libraries(GuardPy sfml-graphics sfml-window sfml-system)

if(WIN32)
    target_link_libraries(GuardPy ws2_32)
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/Assets")
    add_custom_command(TARGET GuardPy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
        "${CMAKE_SOURCE_DIR}/Assets" 
        "$<TARGET_FILE_DIR:GuardPy>/Assets"
    )
endif()
