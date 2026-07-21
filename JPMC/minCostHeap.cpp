// given an array-> take two elements add them replace the two elements. cost is sum of two elements only. find
//min cost to reach one element.
#include <bits/stdc++.h>
using namespace std;

int getCost(vector<int>& a){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>>pqmn;

    for(int i=0;i<n;i++){
        pqmn.push(a[i]);
    }
    int cost=0;
    while(pqmn.size()>1){
       int x=pqmn.top();
       pqmn.pop();
       int y=pqmn.top();
       pqmn.pop();
       cost+=x+y;
       pqmn.push(x+y);
       cout<<x<<" "<<y<<" "<<x+y<<" "<<cost<< " ";
    }
    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    cout << "Minimum Cost is " << getCost(a) << endl;
}
