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
#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll; 

// int main(){
//     ll n;
//     cin>>n; ll k;cin>>k;
//     vector <ll> a(n,0);
//     for(ll i=0;i<=n-1;i++){
//         cin>>a[i];
//     }
//     vector <ll> dp(n,0); dp[0] = 0; 
//     dp[1] = a[0]*a[1];
//     for(ll i=2;i<=n-1;i++){ll u = 0;
//         for(ll j=max(u,i-k);j<=i-1;j++){
//             dp[i] = min(dp[i],a[i]*a[j] + dp[j]) ; 
//         }
//     }
//     cout<<dp[n-1]; 
//     return 0;
// }