// https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>dp(n,0);
    dp[0]=0;
    dp[1]=abs(a[1]-a[0])+dp[0];
    for(int i=2;i<n;i++){
        dp[i]=abs(a[i]-a[i-1])+dp[i-1];
        int j=2;
        while(j<=k && i-j>=0){
         dp[i]=min(abs(a[i]-a[i-j])+dp[i-j],dp[i]);
         j++;
        }
        }
    cout<<dp[n-1]<<endl;
}