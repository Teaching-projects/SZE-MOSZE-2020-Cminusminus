cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=gnu++11") #Turn on C++11 Support

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(FILES_TO_TEST character.cpp player.cpp JSONParser.cpp characterMaker.cpp)
set(UNIT_TESTS main_test.cpp)
set(MAIN_FILE main.cpp)


add_library(codeToTest ${FILES_TO_TEST})

add_executable(mosze ${MAIN_FILE})
target_link_libraries(mosze codeToTest)

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread codeToTest)

