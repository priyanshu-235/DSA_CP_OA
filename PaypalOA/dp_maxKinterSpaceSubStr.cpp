//given a string find the longest k-interspace substring (every adjascent pair ascii diff is atmost k), if more than one max then return the first occuring one
//normal approch is just iteration , and find where breaks . if greater than max then change
#include<bits/stdc++.h>
using namespace std;

 string longestSubStr(string s,int k){
    vector<int>dp(s.size());

    dp[0]=1;
    int mx=dp[0];
    for(int i=1;i<s.size();i++){
        if(abs(s[i]-s[i-1])<=k){
            dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=1;
        }
        mx=max(mx,dp[i]);
    }
    int idx=-1;
   for(int i=0;i<s.size();i++){
    if(dp[i]==mx){idx=i;break;}
    
   }
   string ans="";
   while(mx--){
     ans+=s[idx];
     idx--;
   }

   reverse(ans.begin(),ans.end());
   return ans;


}


int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<"longest substring: "<<longestSubStr(s,k);
}
