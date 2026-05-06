// //Q> Given array find two non-intersecting subarrays with max sum and output their sum
// #include<bits/stdc++.h>
// using namespace std;

// //this question is asking to find two non-overlapping or non intersecting arrays--> to ensure that the arrays are not overlapping we divide it into two partitions with a virtual stick
// //using greedy method we calculate the max when stick is at each index
// //best of (max of lefts and max of rights) we will get the max two subarrays

// //one intution is when the stick is at i then the max is of lefts are max{dp[i]+arr[i],arr[i],0} and the max of rights will 
// //the max of subarrays from right starting from i

// // 1 3 4 -2 | -2 4 5 3 0 -3 -> the max of subarray till i we can calculate from left to right while traversing . but for 
// //each position we have to calculate the max from right till that position.
// // this is because we are sure that both the subarrays will be one from left and one from right as we have been told that 
// // two non-overlapping subarrays.

// //Function to calculate the maximum subarray sum ending at each indes from the left

// vector<int>calculatePrefixMaxSum(const vector<int>& nums){
//     int n=nums.size();
//     vector<int>prefixMaxSum(n+1,0);
//    int currentMax=0;
//     for(int i=1;i<=n;i++){
//         currentMax=max({0,nums[i-1],currentMax+nums[i-1],currentMax});
//         prefixMaxSum[i]=currentMax;
//     }
//     return prefixMaxSum;
// }

// //Function to calculate the maxisum subarray sum starting at each index from the right 

// vector<int>calculateSuffixMaxSum(const vector<int>& nums){
//     int n=nums.size();
//     vector<int>suffixMaxSum(n+1,0);
//     int currentMax=0;
//     for(int i=n-1;i>=0;i--){
//       currentMax=max({0,nums[i],currentMax+nums[i],currentMax});
//       suffixMaxSum[i]=currentMax;
//     }
//     return suffixMaxSum;
// }


// int maxTwoNonOverlappingSubarraysSum(const vector<int>& nums){
//     int n=nums.size();
//     if(n==0)return 0;

//     //calculate prefix and suffix array sums
//     vector<int>prefixMaxSum=calculatePrefixMaxSum(nums);
//     vector<int>suffixMaxSum=calculateSuffixMaxSum(nums);
//     for(int i=0;i<prefixMaxSum.size();i++){
//         cout<<prefixMaxSum[i]<<' '<<suffixMaxSum[i]<<endl;
//     }
//     int maxsum=0;
//     for(int i=1;i<prefixMaxSum.size()-1;i++){
//       maxsum=max(maxsum,prefixMaxSum[i]+suffixMaxSum[i+1]);
//     }
//    return maxsum;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     cout<<"Maximum sum of two non-overlapping subarrays: " << maxTwoNonOverlappingSubarraysSum(nums) << endl;
//     return 0;
// }
//This code is little different from the original one
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum subarray sum ending at each index from the left
vector<int> calculatePrefixMaxSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixMaxSum(n+1, 0);
    int currentMax = nums[1];
    prefixMaxSum[1] = nums[1];
    
    for (int i = 2; i <= n; ++i) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        prefixMaxSum[i] = currentMax;
    }
    
    return prefixMaxSum;
}

// Function to calculate the maximum subarray sum starting at each index from the right
vector<int> calculateSuffixMaxSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> suffixMaxSum(n+1, 0);
    int currentMax = nums[n];
    suffixMaxSum[n] = nums[n];
    
    for (int i = n - 1; i >= 1; --i) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        suffixMaxSum[i] = currentMax;
    }
    
    return suffixMaxSum;
}

int maxTwoNonOverlappingSubarraysSum(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Calculate prefix and suffix max subarray sums
    vector<int> prefixMaxSum = calculatePrefixMaxSum(nums);
    vector<int> suffixMaxSum = calculateSuffixMaxSum(nums);

    vector<int> maxPrefixSum(n+2, 0);
    maxPrefixSum[1] = prefixMaxSum[1];
    for (int i = 2; i <= n; ++i) {
        maxPrefixSum[i] = max(maxPrefixSum[i - 1], prefixMaxSum[i]);
    }

    vector<int> maxSuffixSum(n+2, 0);
    maxSuffixSum[n] = suffixMaxSum[n];
    for (int i = n - 1; i > 0; --i) {
        maxSuffixSum[i] = max(maxSuffixSum[i + 1], suffixMaxSum[i]);
    }

    // Find the maximum sum of two non-overlapping subarrays
    int maxSum = 0;
    for (int i = 0; i <= n ; ++i) {
    	// cout<<maxSum<<"i is "<<i<<endl;
        maxSum = max(maxSum, maxPrefixSum[i] + maxSuffixSum[i + 1]);
    }

    return maxSum;
}

int main() {
	int n;cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
    	cin>>nums[i];
    }
    cout << "Maximum sum of two non-overlapping subarrays: " << maxTwoNonOverlappingSubarraysSum(nums) << endl;
    return 0;
}
