#include <bits/stdc++.h>
using namespace std;

// function to calculate prefix sum
vector<int> calculatePrefixSum(const vector<int>& nums){
    vector<int>prefix(nums.size()+1,0);
    for(int i=1;i<prefix.size();i++){
        prefix[i]=prefix[i-1]+nums[i-1];
    }
    return prefix;
}

// function to calculate max subset sum of size<=k

int findMaxSubsetSum(const vector<int>& nums,int k){
    multiset<int>ms;
    vector<int> prefix=calculatePrefixSum(nums);
    int ans=INT_MIN;
    for(int i=0;i<prefix.size();i++){
        if(ms.size()>=k){
           auto it=ms.find(prefix[i-k-1]);
           if(it!=ms.end()){
            ms.erase(it);
           }
          
        }
        ms.insert(prefix[i]);
        if(i>0)ans=max(ans,prefix[i]-*ms.begin());
    }
    return ans;
    

}

// main
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<findMaxSubsetSum(nums,k)<<endl;
    return 0;
}