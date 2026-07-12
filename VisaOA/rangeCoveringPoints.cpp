// some ranges are given, and some points , we have to tell how many ranges are covering that point.
//we can solve it with simple range update trick
//but if L and R is big >10^9 we use sweep line algo.
//okay so we will make a vector of pairs where first one is value of that point and second denotes their role-startpoint, endpoint, visapoint
//0-start,2-end,1-visa.
// second values matter when first is same, now if some points are starting from x and also ending at x so we will count all, the ending part 
//is already present in cnt , so I would increase the starts and then store for visa point.

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>visa;

void getRangePoints(vector<pair<int,int>>&b){
    int m=b.size();
    sort(b.begin(),b.end());
    int cnt=0;
    for(int i=0;i<m;i++){
    //also we could have stored for all points but it is not neccessary for this question, but if you are storing
    //then make sure for endpoint you store before you change cnt and also if endpoint is not in map already if already there
    //means startpoint has covered it.
      if(b[i].second==0){
        cnt++;
      }
      else if(b[i].second==1){
        visa[b[i].first]=cnt;
      }
      else{
        cnt--;
      }
    }
}

int main(){
    int Q;
    cin>>Q;
    vector<pair<int,int>>b;
    for(int i=0;i<Q;i++){
          int x,y;
          cin>>x>>y;
          b.push_back({x,0});
          b.push_back({y,2});
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back({x,1});
    }
     getRangePoints(b);
    for(auto pair:visa){
        cout<<"range covering:"<<pair.first<<"is "<<pair.second<<endl;
    }
  return 0;
}