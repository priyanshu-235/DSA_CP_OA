//given two arrays b and g find the max value of (b[i]+b[j]...b[k])*(min(g[i],g[j]..g[k]))..basically have to choose and subsequence
// which has max of this val

#include <bits/stdc++.h>
using namespace std;

int getMaxVal(vector<pair<int,int>>& a,int k){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    sort(a.begin(),a.end());
    int ans=INT_MIN;
    int sum=0;
    for(int i=n-1;i>=0;i--){
          if(pq.size()>k-1){
            sum-=pq.top();
            pq.pop();
          }
          sum+=a[i].second;
          pq.push(a[i].second);
        if(pq.size()==k)ans=max(ans,sum*a[i].first);
    }
    return ans;
}
    int main() {
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;//g arrays
        for (int i = 0; i < n; i++) cin >> a[i].second;// b array

        int k;
        cin>>k;
        cout << "Maximum Cost is " << getMaxVal(a,k) << endl;
    }