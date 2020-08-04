


# from https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html#add-google-tests

# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR} ${GTEST_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run testGraph.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main Graph VF2Wrapper)