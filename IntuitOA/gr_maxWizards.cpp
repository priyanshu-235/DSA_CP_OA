//given two arrays ai and bi, return the max number of i for which there doesn't exist any value strictly greater than it w.r.t a and b both.

#include<bits/stdc++.h>
using namespace std;


int getWizards(const vector<int>& a , const vector<int>& b,int n){
      vector<pair<int,int>>c(n);
      for(int i=0;i<n;i++){
        c[i]={a[i],b[i]};
      }
      sort(c.begin(),c.end());
      int cnt=1;
       int mx=c[n-1].second;
       int mxp=INT_MIN;
      int have=0;
    
      for(int i=n-2;i>=0;i--){
        cout<<"c[i].first:"<<c[i].first<< " "<<"c[i].second:"<<c[i].second<<endl;
       if(c[i].first!=c[i+1].first){
        have++;
        mxp=max(mx,mxp);
        mx=c[i].second;
        cout<<"mx"<<mx<<"mxp"<<mxp<<endl;
        }
       if(have>0){
          if(c[i].second>=mxp)cnt++;
       }
       else{
        cnt++;
       }
      }
   return cnt;
}


int main(){
    int n; cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    cout<<"max wizards that can advance to tournament is: " << getWizards(a,b,n)<<endl;
}

// #include <bits/stdc++.h>
// using namespace std;

// int getWizards(const vector<int>& a , const vector<int>& b,int n){
//     vector<pair<int,int>> c(n);
//     for(int i=0;i<n;i++){
//         c[i] = {a[i], b[i]};
//     }
//     sort(c.begin(), c.end());

//     int cnt = 1;
//     int mx = c[n-1].second;

//     for(int i=n-2; i>=0; i--){
//         if(c[i].first==c[i+1].first)cnt++;
//         else if(c[i].second >= mx){
//             cnt++;
//             mx = c[i].second;
//         }
//     }
//     return cnt;
// }

// int main(){
//     int n; cin >> n;
//     vector<int> a(n), b(n);
//     for(int i=0;i<n;i++) cin >> a[i];
//     for(int i=0;i<n;i++) cin >> b[i];

//     cout << "max wizards that can advance to tournament is: "
//          << getWizards(a,b,n) << endl;
// }
