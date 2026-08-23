//given A,B,C array find the max happiness gained till N days, doing any one of the activities on ith day given that same activity 
//can't be done consecutively

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxHappiness(int n, vector<int>& A,vector<int>& B, vector<int>& C){
    
    vector<vector<int>>dp(3,vector<int>(n));
    dp[0][0]=A[0];
    dp[1][0]=B[0];
    dp[2][0]=C[0];
    for(int i=1;i<n;i++){
        dp[0][i]=max(dp[1][i-1],dp[2][i-1])+A[i];
        dp[1][i]=max(dp[0][i-1],dp[2][i-1])+B[i];
        dp[2][i]=max(dp[0][i-1],dp[1][i-1])+C[i];
    }
   return max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
}


int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    vector<int>B(n);
    vector<int>C(n);
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i]>>C[i];
    }
    cout<<"Max Happiness: "<<maxHappiness(n,A,B,C);
    return 0;
}