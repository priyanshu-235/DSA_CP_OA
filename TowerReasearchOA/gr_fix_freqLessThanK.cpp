// given an array , you have to make sure freq. of any two elements ≤k , in one operation you can remove 1 number. Min operations

#include<bits/stdc++.h>
using namespace std;

int getMinOpt(const vector<int>& f,int k){
 int n=f.size();
 // now we will check for each i..j
// the cost to get i..j valid is cost(1...i-1)+cost_to_make_i..j_valid+cost(j+1..N);
vector<int>prefix(n+1,0);
        for(int i=1;i<=n;i++){
          prefix[i]=prefix[i-1]+f[i-1];
        }
     int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int cost=0;
        for(int j=i+1;j<n;j++){
         if(f[j]>f[i])cost+=f[j]-(k-f[i]);
         ans=min(ans,(int)(prefix[i]+cost+(prefix[n]-prefix[j])));
        }
        
    }
    return ans;

}


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    vector<int>f;  
      for(auto p:mp){
        f.push_back(p.second);
    }
    sort(f.begin(),f.end());

    int ans=getMinOpt(f,k);
}