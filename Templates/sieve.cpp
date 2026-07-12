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
