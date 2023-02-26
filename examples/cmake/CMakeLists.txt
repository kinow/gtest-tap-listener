cmake_minimum_required(VERSION 3.5)

project(gtest-tap-listener-example-cmake LANGUAGES CXX)

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
FetchContent_MakeAvailable(googletest)

enable_testing()

# Include the local copy of gtest-tap-listener. You may prefer to use a
# GIT option in your project instead.
include(FetchContent)
FetchContent_Declare(
  gtest-tap-listener
  SOURCE_DIR "${PROJECT_SOURCE_DIR}/../../"
)
FetchContent_MakeAvailable(gtest-tap-listener)
#find_package(gtest-tap-listener REQUIRED CONFIG)

add_executable(${PROJECT_NAME})

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/gtest_testHelloWorld.cc"
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  gtest-tap-listener
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests("${PROJECT_NAME}")

