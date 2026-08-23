//given A array find the number of odd journeys that is given that you are allowed to take 1 and 2 jumps , how many journey sum will be 
//odd
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int cntOddJourney(int n, vector<int>& A){
    
    vector<vector<int>>dp(2,vector<int>(n));
    //dp[0][i]-> number of journeys that are odd till i
    //dp[1][i]-> number of journey that are even till i
    dp[0][0]=(A[0]%2==1?1:0);
    dp[1][0]=(A[0]%2==0?1:0);
    if(A[1]==0){
        dp[0][1]=dp[0][0];
        dp[1][1]=dp[1][0];
    }
    else{
        dp[0][1]=dp[1][0];
        dp[1][1]=dp[0][0];
    }
    for(int i=2;i<n;i++){
        
        if(A[i]%2==1){
            dp[0][i]=dp[1][i-1]+dp[1][i-2];
            dp[1][i]=dp[0][i-1]+dp[0][i-2];
        }
        else{
            dp[0][i]=dp[0][i-1]+dp[0][i-2];
            dp[1][i]=dp[1][i-1]+dp[1][i-2];
        }

    }
    return dp[0][n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int>A(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"odd Journeys: "<<cntOddJourney(n,A);
    return 0;
}