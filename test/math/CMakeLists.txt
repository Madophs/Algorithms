INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/math PRIVATE)

add_executable(
    gcd_test
    gcd_test.cc
)

target_link_libraries(
    gcd_test
    gtest_main
)

INCLUDE(GoogleTest)
gtest_discover_tests(gcd_test)
