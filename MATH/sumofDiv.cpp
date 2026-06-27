#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// Fast range sum: sum of integers from l to r
long long range_sum(long long l, long long r) {
    long long cnt = (r - l + 1) % MOD;
    long long sum_lr = ((l + r) % MOD) * cnt % MOD;
    // divide by 2 safely under MOD (use modular inverse of 2)
    long long inv2 = (MOD + 1) / 2;
    return sum_lr * inv2 % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long ans = 0;
    long long d = 1;

    while (d <= n) {
        long long q = n / d;       // current quotient
        long long r = n / q;       // last d giving same q

        // sum of all d in [d, r]
        long long sumD = range_sum(d, r);

        // contribution: q * sumD
        ans = (ans + sumD * (q % MOD)) % MOD;

        d = r + 1; // jump to next block
    }

    cout << ans % MOD << "\n";
    return 0;
}
