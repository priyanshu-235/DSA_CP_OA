//given N , Min steps to reduce N to 1 . 3 ops-> divide by 2, divide by 3 , -1

#include<bits/stdc++.h>
using namespace std;


int minSteps(int n){
    vector<int>dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=min({dp[i-1],(i%2==0?dp[i/2]:INT_MAX),(i%3==0?dp[i/3]:INT_MAX)})+1;
    }
    return dp[n-1];
}
//another version if the number is even you can divide it by 2 and if odd then you can do +1 and -1
// here we have to store different states

int main(){
    int n;
    cin>>n;
    

    cout<<"Min Steps:"<<minSteps(n);
}