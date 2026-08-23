//given an cost array find the min cost to reach N , cost(i..j)=abs(cost(i)-cost(j))
#include<bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& c){
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=abs(c[1]-c[0]);
    dp[2]=abs(c[2]-c[1])+dp[1];
    for(int i=3;i<n;i++){
        dp[i]=min(abs(c[i]-c[i-1])+dp[i-1],abs(c[i]-c[i-3])+dp[i-3]);
    }
   return dp[n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    cout<<"MIN COST: "<<minCost(n,c);
}