//given an array of integers find the lexicographically smallest subsequence

#include <bits/stdc++.h>
using namespace std;

void getLexiSmallSSofK(vector<int>& a,int k){
    int n=a.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mpq;
   int i=0;
   vector<int>ans;
    while(i<n-k+1){
      mpq.push({a[i],i});
      i++;
    }
    int prv=-1;
    pair<int,int> p=mpq.top();
    mpq.pop();
    ans.push_back(p.first);
    prv=p.second;
    for(;i<n;i++){
        mpq.push({a[i],i});
        while(mpq.top().second<prv){
            mpq.pop();
        }
        pair<int,int> p=mpq.top();
        mpq.pop();
        ans.push_back(p.first);
        prv=p.second;
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }
}



int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    getLexiSmallSSofK(a,k);
    return 0;
}