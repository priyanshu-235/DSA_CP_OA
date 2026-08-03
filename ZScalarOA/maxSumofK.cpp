//given a array consisting of neg and positive values, find max sum of subarrays whose length is <=k

#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int>& a,int k){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
    }
    int i=1;
    int ans=INT_MIN;
    while(i<=n){
    while(pq.size()>k){
        pq.pop(prefix[i-k-1]);
    }
    while(pq.size()<=k){
       pq.push(prefix[i]);
       ans=max(ans,prefix[i]-pq.top());
       i++;
    }
}
}


    int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int k;
        cin>>k;
        cout << "Minimum Cost is " << getMaxSum(a,k) << endl;
    }
    