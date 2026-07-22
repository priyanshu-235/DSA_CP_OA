// You are given an array of coordinates where policemen are located on the X-axis. 
// You have to deploy “k” family members in the city 
// But you want them safe so try to put them as close as possible to policemen. 
// But each member should be at a different location and not at the same location as the police! 
#include <bits/stdc++.h>
using namespace std;

void getPoints(vector<int>& p,int k){
    vector<int>visited(1e5,0);
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int n=p.size();
    for(int i=0;i<n;i++){
         pq.push({0,p[i]});
         visited[p[i]]=1;
    }
    int cnt=k+n;
    int minCost=0;
    while(cnt--){
        pair<int,int> loc=pq.top();
        pq.pop();
        int cur=loc.second;
        int dist=loc.first;
        if(!visited[cur+1]){
            pq.push({dist+1,cur+1});//dist+1 is written because it will always cover the closest points of all2 the points
            //it will never happen that a point closest to another point will be covered in another point dist
        }
        if(!visited[cur-1]){
            pq.push({dist+1,cur-1});
        }
        if(dist!=0){
            ans.push_back(cur);
        }
        minCost+=dist;
    }
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" \n"[i==ans.size()-1];
   }
   cout<<"MinCost:"<<minCost<<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cin>>k;
    getPoints(a,k);
    return 0;
}