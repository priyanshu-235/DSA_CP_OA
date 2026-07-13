#include <bits/stdc++.h>
using namespace std;

long long countQuadraples(vector<int>& a) {
    int n = a.size();
    vector<int> pre1(n), pre2(n);

    // pre1[i] = count of elements before i that are greater than a[i]
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) cnt++;
        }
        pre1[i] = cnt;
    }

    // pre2[i] = count of elements after i that are smaller than a[i]
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) cnt++;
        }
        pre2[i] = cnt;
    }

    long long ans = 0;
    // choose j,k with j<k and a[j]<a[k]
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (a[j] < a[k]) {
                ans += 1LL * pre1[j] * pre2[k];
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << countQuadraples(a) << "\n";
    return 0;
}
