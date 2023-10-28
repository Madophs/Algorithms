include_directories(${CMAKE_SOURCE_DIR}/dynamic_programming PRIVATE)

add_executable(arithmetic_expression_test arithmetic_expression_test.cc)

target_link_libraries(
    arithmetic_expression_test
    gtest_main
    arithmetic_expression
)

gtest_discover_tests(arithmetic_expression_test)

