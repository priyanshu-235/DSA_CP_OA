//question is given a array find number of subarrays for which sum of subarray %k = length of that subarray.


#include <bits/stdc++.h>
using namespace std;

long long findSecurityLevel(vector<int>& pid, int k) {
    int n = pid.size();
    long long ans = 0;
    long long prefix = 0;

    // Map: key -> frequency
    unordered_map<long long, long long> freq;
    freq[0] = 1; // base case

    for (int i = 0; i < n; i++) {
        prefix += pid[i];

        // Key = (prefix % k - (i+1) % k + k) % k
        long long key = (prefix % k - (i + 1) % k + k) % k;

        ans += freq[key];
        freq[key]++;
    }

    return ans;
}

int main() {
    vector<int> pid = {1, 3, 2, 4};
    int k = 4;
    cout << findSecurityLevel(pid, k) << endl; // Output: 2
    return 0;
}