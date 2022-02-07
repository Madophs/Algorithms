INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/math PRIVATE)

add_executable(gcd_test gcd_test.cc)
add_executable(extended_euclidean_test extended_euclidean_test.cc)
add_executable(sieve_eratosthenes_test sieve_eratosthenes_test.cc)
add_executable(prime_factors_test prime_factors_test.cc)

target_link_libraries(
    gcd_test
    gtest_main
)

target_link_libraries(
    extended_euclidean_test
    gtest_main
)

target_link_libraries(
    sieve_eratosthenes_test
    gtest_main
)

target_link_libraries(
    prime_factors_test
    gtest_main
)

gtest_discover_tests(gcd_test)
gtest_discover_tests(extended_euclidean_test)
gtest_discover_tests(sieve_eratosthenes_test)
gtest_discover_tests(prime_factors_test)
