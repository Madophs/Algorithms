#ifndef __PRIME_FACTORS_H__
#define __PRIME_FACTORS_H__

#include "sieve_eratosthenes.hpp"

vector<int> primeFactors(int64_t n) {
    vector<int> primes = sieveEratosthenes(n);
    vector<int> factors;

    for (int i = 0; i < (int)primes.size() && ((int64_t)primes[i] * (int64_t)primes[i]) <= n; ++i) {
        while (n > 0 && n % (int64_t)primes[i] == 0) {
            n /= primes[i];
            factors.push_back(primes[i]);
        }
    }

    // N is prime
    if (n)
        factors.push_back(n);
    return factors;
}
#endif
