# NOTE: This file was added in order to build it with GH Actions, and in an
#       effort to have an initial CMake setup. Any community help to improve
#       it and make it easier for external projects to use it would be
#       appreciated.
#       This CMakeLists.txt and the one in the examples/cmake directory were
#       both created using this excellent Git repository as reference:
#       <https://github.com/pr0g/cmake-examples/>.

cmake_minimum_required(VERSION 3.5)

project(gtest-tap-listener VERSION 0.7 LANGUAGES CXX)

# Define GNU standard installation directories. Introduces variables:
# * CMAKE_INSTALL_LIBDIR
# * CMAKE_INSTALL_BINDIR
# * CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

set(GTEST_TAP_LISTENER_VERSION 0.7)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

# To silence a FetchContent_Declare warning
if (POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(${PROJECT_NAME} INTERFACE)

# Source: https://github.com/pr0g/cmake-examples/blob/main/examples/core/header-only/library/CMakeLists.txt
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  VERSION
  ${PROJECT_VERSION}
)

install(
  TARGETS
  ${PROJECT_NAME}
  EXPORT
  ${PROJECT_NAME}-config
)

install(
  EXPORT ${PROJECT_NAME}-config
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

export(
  TARGETS
  ${PROJECT_NAME}
  FILE
  ${PROJECT_NAME}-config.cmake
)
