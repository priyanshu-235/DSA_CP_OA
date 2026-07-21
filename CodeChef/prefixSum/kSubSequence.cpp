#include <bits/stdc++.h>
using namespace std;

long long getSum(int l, int r, int k, vector<vector<int>>& p) {
    if (k == 0) return 0;
    if (l > r) return -(1LL << 60);

    long long sum = 0;
    for (int m = 50; m > 0; m--) {
        if (k == 0) break;
        int x = p[m][r + 1] - p[m][l];
        int take = min(k, x);
        sum += 2LL * take * m;
        k -= take;
    }

    if (k > 0) return -(1LL << 60);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> prefix(51, vector<int>(n + 1, 0));
        vector<int> a(n);
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!mp1.count(a[i])) mp1[a[i]] = i;
            mp2[a[i]] = i;
        }

        for (int val = 1; val <= 50; val++) {
            for (int j = 0; j < n; j++) {
                prefix[val][j + 1] = prefix[val][j] + (a[j] == val);
            }
        }

        long long ans = 0;

        for (int i = 1; i <= 50; i++) {
            if (!mp1.count(i)) continue;

            for (int j = 1; j <= 50; j++) {
                if (!mp2.count(j)) continue;

                int L = mp1[i];
                int R = mp2[j];

                if (L >= R) continue;
                if (R - L - 1 < k - 2) continue;

                long long mid = getSum(L + 1, R - 1, k - 2, prefix);
                if (mid < 0) continue;

                ans = max(ans, mid + i + j);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}