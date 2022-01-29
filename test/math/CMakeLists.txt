INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/math PRIVATE)

INCLUDE(GoogleTest)

add_executable(gcd_test gcd_test.cc)
add_executable(extended_euclidean_test extended_euclidean_test.cc)

target_link_libraries(
    gcd_test
    gtest_main
)

target_link_libraries(
    extended_euclidean_test
    gtest_main
)


gtest_discover_tests(gcd_test)
gtest_discover_tests(extended_euclidean_test)
