#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long fiveSumCount(vector<int>& nums1, vector<int>& nums2,
                           vector<int>& nums3, vector<int>& nums4,
                           vector<int>& nums5) {
        int n = nums1.size();
        unordered_map<int,long long> sumFreq;

        // Step 1: store all triplet sums from nums1, nums2, nums3
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    sumFreq[nums1[i] + nums2[j] + nums3[k]]++;
                }
            }
        }

        // Step 2: check pairs from nums4 and nums5
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int need = -(nums4[i] + nums5[j]);
                if (sumFreq.count(need)) {
                    ans += sumFreq[need];
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums2(n), nums3(n), nums4(n), nums5(n);

    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    cout << "Enter elements of nums3: ";
    for (int i = 0; i < n; i++) cin >> nums3[i];

    cout << "Enter elements of nums4: ";
    for (int i = 0; i < n; i++) cin >> nums4[i];

    cout << "Enter elements of nums5: ";
    for (int i = 0; i < n; i++) cin >> nums5[i];

    Solution sol;
    long long result = sol.fiveSumCount(nums1, nums2, nums3, nums4, nums5);

    cout << "Number of quintuplets: " << result << "\n";
    return 0;
}
