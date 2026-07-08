/*You are given an integer array arr of length n and an integer k.

At any index i, you may perform the operation:
    arr[i] → arr[i] + x   where x ∈ [-k, k]

After performing operations (possibly different x for different indices),
determine the maximum length of a subsequence where all elements are equal.
*/
//first solution
#include <bits/stdc++.h>
using namespace std;

int maxEqualSubseqRangeUpdate(vector<int>& arr, int k) {
    int n = arr.size();
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());

    // Range size: from mn-k to mx+k
    int offset = mn - k;
    int size = (mx + k - offset + 2); 
    vector<int> freq(size, 0);

    for (int val : arr) {
        int L = val - k - offset;
        int R = val + k - offset;
        freq[L] += 1;
        if (R + 1 < size) freq[R + 1] -= 1;
    }

    int ans = 0, curr = 0;
    for (int x : freq) {
        curr += x;
        ans = max(ans, curr);
    }
    return ans;
}
// //second
// int main() {
//     vector<int> arr = {1, 5, 9};
//     int k = 3;
//     cout << maxEqualSubseqRangeUpdate(arr, k) << endl; // Output: 2
// }
// int maxEqualSubseqBinarySearch(vector<int>& arr, int k) {
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     int mn = arr.front();
//     int mx = arr.back();
//     int ans = 1;

//     // Check every possible target value between [mn-k, mx+k]
//     for (int val = mn - k; val <= mx + k; val++) {
//         int L = lower_bound(arr.begin(), arr.end(), val - k) - arr.begin();
//         int R = upper_bound(arr.begin(), arr.end(), val + k) - arr.begin();
//         ans = max(ans, R - L);
//     }
//     return ans;
// }

// int main() {
//     vector<int> arr = {1, 5, 9};
//     int k = 3;
//     cout << maxEqualSubseqBinarySearch(arr, k) << endl; // Output: 2
// }
