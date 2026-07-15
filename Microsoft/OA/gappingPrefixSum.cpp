#include <bits/stdc++.h>
using namespace std;

int gappingPrefixSum1(vector<int>& arr, int x, int y) {
    int n = arr.size();
    vector<long long> b(n);
    // Build gapping prefix sum
    for (int i = 0; i < n; i++) {
        b[i] = arr[i];
        if (i - y >= 0) b[i] += b[i - y];
    }

    long long ans = LLONG_MAX;
    for (int i = x * y; i < n; i++) {
        long long g = b[i] - b[i - x * y];
        ans = min(ans, g);
    }
    return (ans == LLONG_MAX ? -1 : ans);
}
#include <bits/stdc++.h>
using namespace std;

long long gappingPrefixSumSliding(vector<int>& arr, int x, int y) {
    int n = arr.size();
    long long ans = LLONG_MAX;

    // Try all starting offsets from 0 to y-1
    for (int s = 0; s < y; s++) {
        // Build initial window
        long long windowSum = 0;
        vector<int> indices;
        for (int i = 0; i < x; i++) {
            int idx = s + i * y;
            if (idx >= n) { windowSum = LLONG_MAX; break; }
            windowSum += arr[idx];
            indices.push_back(idx);
        }
        if (windowSum == LLONG_MAX) continue;
        ans = min(ans, windowSum);

        // Slide window forward
        int start = s;
        while (start + x * y < n) {
            windowSum -= arr[start];                // remove first element
            windowSum += arr[start + x * y];        // add next element
            start += y;                             // move window forward
            ans = min(ans, windowSum);
        }
    }
    return (ans == LLONG_MAX ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cout << "Enter n, x, y: ";
    cin >> n >> x >> y;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Method 1 result: " << gappingPrefixSum1(arr, x, y) << "\n";
    cout << "Method 2 result: " << gappingPrefixSumSliding(arr, x, y) << "\n";

    return 0;
}
