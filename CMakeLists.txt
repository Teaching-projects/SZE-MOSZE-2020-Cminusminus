cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=gnu++17") #Turn on C++17 Support

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(FILES_TO_TEST Monster.cpp Hero.cpp JSON.cpp)
set(UNIT_TESTS main_test.cpp)
set(MAIN_FILE main.cpp)


add_library(codeToTest ${FILES_TO_TEST})

add_executable(mosze ${MAIN_FILE})
target_link_libraries(mosze codeToTest)

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread codeToTest)

