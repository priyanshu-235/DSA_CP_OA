#include<bits/stdc++.h>
using namespace std;

//max adjascent pair xor sum given x which can be added to all the numbers of a chosen subsequence
//function to find AdjXorSum
int maxAdjXorSum(vector<int>& arr,int n,int x){
   vector<vector<int>>dp(2,vector<int>(n));
   int a1=arr[0];
 // as dp stores best score till i and for first value xor can't be calculated so it is zero.
  dp[0][0]=0;
  dp[1][0]=0;
  // first xor will be calculated from 1st index.
  dp[0][1]=max(a1^arr[1],((a1+x)^arr[1]));
  dp[1][1]=max(a1^(arr[1]+x),(a1+x)^(arr[1]+x));
  for(int i=2;i<n;i++){
    dp[0][i]=max((arr[i-1]^arr[i])+dp[0][i-1],((arr[i-1]+x)^arr[i])+dp[1][i-1]);// here we won't add x to arr[i] and since for 
    //first term we didn't take x for arr[i-1] also so we will take best answer when arr[i-1] is not added to x i.e dp[0][i-1] and sams for second term
    dp[1][i]=max((arr[i-1]^(arr[i]+x))+dp[0][i-1],((arr[i-1]+x)^(arr[i]+x))+dp[1][i-1]);
  }
  return max(dp[0][n-1],dp[1][n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<"Maximum Adjascent pair sum is:"<<maxAdjXorSum(arr,n,x)<<endl;
    return 0;
}