//given N find min cost to reduce N to 1 , 4 ops-> reduce by 1 in x dollar, reduce by /7 in y dollar, reduce by /3 in z dollar, reduce
//by /5 in b dollar if div.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minCost(int n, int x, int y , int z, int b){
    vector<int>dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=min({dp[i-1]+x,(i%7==0?dp[i/7]+y:INT_MAX),(i%3==0?dp[i/3]+z:INT_MAX),(i%5==0?dp[i/5]+z:INT_MAX)});
    }
    return dp[n-1];
}


int main(){
    int n;
    cin>>n;
    int x,y,z,b;
    cin>>x>>y>>z>>b;

    cout<<"Min Reduction Cost: "<<minCost(n,x,y,z,b);
    return 0;
}