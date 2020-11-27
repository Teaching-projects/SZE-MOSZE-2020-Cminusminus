cmake_minimum_required(VERSION 2.6)
project(SZE-MOSZE-2020-Cminusminus)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit-test main_test.cpp JSON.cpp Hero.cpp Monster.cpp Map.cpp Game.cpp) 
target_link_libraries(unit-test ${GTEST_LIBRARIES} pthread)