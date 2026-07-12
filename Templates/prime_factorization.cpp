
#include <bits/stdc++.h>
using namespace std;
// Generate primes up to sqrt(n) using sieve
vector<int> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// Optimized prime factorization
vector<pair<int,int>> primeFactorization(long long n) {
    vector<pair<int,int>> factors;
    int limit = sqrt(n);
    vector<int> primes = sieve(limit);

    for (int p : primes) {
        if (p * 1LL * p > n) break;
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }
    if (n > 1) {
        // Remaining prime factor larger than sqrt(n)
        factors.push_back({(int)n, 1});
    }
    return factors;
}