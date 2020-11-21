cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=gnu++17") #Turn on C++11 Support
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
#Locate GTest
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
target_compile_features(unit-test PRIVATE cxx_std_17)

cmake_minimum_required(VERSION 2.6)
project(SZE-MOSZE-2020-Cminusminus)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit-test projectTest.cpp JSON.cpp Hero.cpp Monster.cpp) 
target_link_libraries(unit-test ${GTEST_LIBRARIES} pthread)