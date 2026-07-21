#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
int OR_range(const vector<vector<int>>& prefix, int i, int j) {
    int k = 0;
    for (int u = 0; u <= 30; u++) {
        int one = prefix[u][j] - (i > 0 ? prefix[u][i - 1] : 0);
        if (one >= 1) {
            k += (1 << u);
        }
    }
    return k;
}

    int minimumSubarrayLength(vector<int>& nums, int k) {

        long long n=nums.size();
        long long cur=0;
        long long ans=LLONG_MAX;
            vector<vector<int>> bit(31, vector<int>(n));
       for (int j = 30; j >= 0; j--) {
        for (long long i = 0; i < n; i++) {
            bit[j][i] = nums[i] & (1 << j);
          }
       }
           vector<vector<int>> prefix(31, vector<int>(n));
        for (int j = 30; j >= 0; j--) {
            for (long long i = 0; i < n; i++) {
                prefix[j][i] = bit[j][i] + (i > 0 ? prefix[j][i - 1] : 0);
            }
        }
        for(long long i=0,j=0;j<n;j++){
             cur=OR_range(prefix,i,j);

while (cur >= k) {
    ans = min(ans, j - i + 1);
    i++;
    if (i <= j) {
        cur = OR_range(prefix, i, j);
    } else {
        cur = 0; // empty window
    }
}

        } 

      return ans;
       

    }
};

// this might give TLE

class Solution {
public:
    void performOR(vector<int>& bitCnt,int& orVal,int val){
        orVal=(orVal| val);
        for(int u=0;u<32;u++){
            bitCnt[u]+=(val & (1<<u))?1:0;
            
        }
        
    }
    void nullifyOR(vector<int>& bitCnt,int& orVal, int val){
        for(int u=0;u<32;u++){
              bitCnt[u]+=(val & (1<<u))?-1:0;
              if(bitCnt[u]==0) orVal=orVal & (~(1<<u));
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int  orVal=0;
        long long n=nums.size();
        long long ans=LLONG_MAX;
        vector<int>bitCnt(32,0);
    for(long long i=0,j=0;j<n;j++){
            performOR(bitCnt,orVal,nums[j]);
            while (orVal >= k) {
                ans = min(ans,(j - i + 1));
                i++;
                if (i <= j) {
                    nullifyOR(bitCnt,orVal,nums[i]);
                } // empty window
            }

        } 

      return ans==LLONG_MAX?-1:ans;
       

    }
};