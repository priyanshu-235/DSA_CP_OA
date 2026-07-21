  #include <bits/stdc++.h>
using namespace std;

int OR_range(const vector<vector<int>>& prefix, int i, int j) {
    int k = 0;
    for (int u = 0; u <= 30; u++) {
        int one = prefix[u][j] - (i > 0 ? prefix[u][i - 1] : 0);
        if (one >= 1) {
            k |= (1 << u);
        }
    }
    return k;
}

int main() {
    vector<int> nums = {1, 3, 4, 5, 6};
    int n = nums.size();

    vector<vector<int>> bit(31, vector<int>(n));
    for (int j = 30; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            bit[j][i] = nums[i] & (1 << j);
        }
    }

    vector<vector<int>> prefix(31, vector<int>(n));
    for (int j = 30; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            prefix[j][i] = bit[j][i] + (i > 0 ? prefix[j][i - 1] : 0);
        }
    }

    int i = 1, j = 3;
    cout << OR_range(prefix, i, j) << '\n';
    return 0;
}
