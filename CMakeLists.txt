cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project

enable_testing() #to  discover tests in test explorer

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(tests main.cpp) # add this executable

target_link_libraries(tests PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(tests)
