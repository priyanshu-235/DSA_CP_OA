#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            // Start from i*i instead of 2*i
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

//odd only sieve
// 🔑 Why we only go up to √n
// When you’re marking multiples in the sieve, you don’t need to check primes beyond √n because:
// Suppose you’re at a prime p.
// If p > √n, then p * p > n.
// That means any composite number ≤ n must already have been marked by a smaller prime factor.
// In other words:
// Every composite number ≤ n has at least one prime factor ≤ √n.
// So once you’ve crossed √n, all remaining numbers that are still marked as prime are indeed prime — no further marking is needed
vector<bool> sieve_odd_only(int n) {
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    // Mark even numbers as non-prime
    for (int j = 4; j < n; j += 2)
        is_prime[j] = false;

    // Only check odd numbers
    for (int i = 3; i * i < n; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += 2 * i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}

int main() {
    int n;
    cin >> n;
    vector<bool> primes = sieve_odd_only(n);

    for (int i = 2; i < n; i++) {
        if (primes[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}
