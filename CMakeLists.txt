cmake_minimum_required(VERSION 3.5)

project(GTestTapListener VERSION 0.7 LANGUAGES CXX)
set(GTEST_TAP_LISTENER_VERSION 0.7)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_library(${PROJECT_NAME} INTERFACE src/)
