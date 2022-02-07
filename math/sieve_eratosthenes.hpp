#ifndef __SIEVE_ERATOSTHENES_H__
#define __SIEVE_ERATOSTHENES_H__

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#define SIEVE_RANGE 10000000LL

using namespace std;

vector<int> sieveEratosthenes(long long n)
{
    bitset<SIEVE_RANGE> sieve;
    sieve.set();

    int aproxPrimes = n / logl(n);
    vector<int> primes;
    if (aproxPrimes < primes.max_size())
        primes.reserve(aproxPrimes);

    int limit = min(n+1, SIEVE_RANGE);
    for (int i = 2; i < limit; ++i) {
        // if not prime continue
        if (!sieve.test(i))
            continue;

        for (int j = i+i; j < limit; j += i) {
            sieve.reset(j);
        }
        primes.emplace_back(i);
    }
    return primes;
}

#endif
