cmake_minimum_required(VERSION 3.8)

project(triangle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_LIST main.cpp)
#set(TESTS tests/tests.cpp)


add_executable(${PROJECT_NAME} ${SRC_LIST})

set(debug_flags OFF)
if ("${CMAKE_BUILD_TYPE}" STREQUAL "debug")
    set(debug_flags ON)
endif()

if (debug_flags)
    set(compile_flags -Og -Wpedantic -Wall -Wextra)
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG=1)
else()
    set(compile_flags -O2)
endif()


target_compile_options(${PROJECT_NAME} PUBLIC ${compile_flags})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
