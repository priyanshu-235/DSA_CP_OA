#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long power(long long base, long long exp) {
long long result = 1;


while (exp > 0) {
    if (exp & 1) {
        result = result * base ;
    }
    base = base * base ;
    exp >>= 1;
}

return result;
}
const int MAX=1e7;
long long modInverse(long long a) {
    return power(a, MOD - 2);
}

vector<int> precompute() {
    vector<int> sieve(MAX+1, 0);
    for (int i = 2; i <= MAX; i++) {
        if (sieve[i] == 0) { // prime
            sieve[i] = i;
            if ((long long)i * i <= MAX) {
                for (long long j = 1LL * i * i; j <= MAX; j += i) {
                    if (sieve[j] == 0) sieve[j] = i;
                }
            }
        }
    }
    return sieve;
}

long long getDivisorSum(int x, vector<int>& sieve) {
    long long ans = 1;
    while (x > 1) {
        int spf = sieve[x];
        int exponent = 0;
        while (x % spf == 0) {
            x /= spf;
            exponent++;
        }
        ans*=(power(spf, exponent+1) - 1)/(spf-1);
    }
    return ans;
}

// int main() {
//     int n;
//     cin >> n;
//     vector<int> sieve = precompute();
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         if(x==0 || x==1)cout<<0<<endl;
     
//         else
//         cout << getDivisorSum(x, sieve)-x << endl;
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1e6;   // adjust depending on maximum input size
// vector<int> sieve(MAX + 1, 0);

// // Precompute smallest prime factors
// void precompute() {
//     for (int i = 2; i <= MAX; ++i) {
//         if (sieve[i] == 0) { // i is prime
//             for (int j = i; j <= MAX; j += i) {
//                 if (sieve[j] == 0) sieve[j] = i;
//             }
//         }
//     }
// }

// // Solve one test case: compute sum of proper divisors
// void solve() {
//     int n;
//     cin >> n;

//     int N = n;
//     long long res = 1;

//     while (n > 1) {
//         int spf = sieve[n];   // smallest prime factor
//         int alpha = 0;
//         while (n % spf == 0) {
//             alpha++;
//             n /= spf;
//         }
//         // formula for sum of powers of prime factor
//         res *= (pow(spf, alpha + 1) - 1) / (spf - 1);
//     }

//     cout << res - N << endl; // subtract N to get sum of proper divisors
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     precompute();

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
