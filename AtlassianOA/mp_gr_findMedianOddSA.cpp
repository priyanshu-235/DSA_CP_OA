#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u;
    cin >> n >> u;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Transform the array as per the rules
    // < u => -1, == u => 0, > u => +1
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] < u) b[i] = -1;
        else if (a[i] == u) b[i] = 0;
        else b[i] = 1;
    }

    //

    ll prefix_sum = 0;
    ll count = 0;
    unordered_map<ll, ll> freq_even, freq_odd;
    // Initialize frequency for prefix sum 0 at index 0 (even)
    freq_even[0] = 1;

    for (int i = 1; i <= n; i++) {
       // prefix_sum +=  Maps for frequency of prefix sums at even and odd indices
         prefix_sum+=b[i];
        if (i % 2 == 1) {
            // odd index, add count of prefix sums seen at even indices equal to prefix_sum
    
            if(freq_even.count(prefix_sum))count += freq_even[prefix_sum];
            freq_odd[prefix_sum]++;
        } else {
            // even index, add count of prefix sums seen at odd indices equal to prefix_sum
            if(freq_odd.count(prefix_sum)) freq_odd[prefix_sum];
            freq_even[prefix_sum]++;
        }
    }

    cout << count << "\n";

    return 0;
}
