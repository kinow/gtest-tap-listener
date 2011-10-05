CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (gtest_tap)

IF(MSVC) # On Visual Studio use gtest
    SET(EXTRA_LIBS gtest gtest_main pthread)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../gmock/libWin32)
ELSE() # else Unix alike systems (assuming Linux)
    SET(EXTRA_LIBS gtest gtest_main pthread)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../gmock/libLinux)
ENDIF()

INCLUDE_DIRECTORIES (
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/../commoncode
    ${PROJECT_SOURCE_DIR}/../gmock/include)

ADD_EXECUTABLE(helloWorld
    helloworld/helloWorld.cc
    helloworld/greeting.cc)

ADD_EXECUTABLE(testHelloWorld
    test/gtest_testHelloWorld.cc
    test/gtest_main.cc
    helloworld/greeting.cc)

TARGET_LINK_LIBRARIES(testHelloWorld ${EXTRA_LIBS})

