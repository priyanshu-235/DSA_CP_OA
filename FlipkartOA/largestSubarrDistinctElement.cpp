//given n elements find largest subarray with distinct element

#include <bits/stdc++.h>
using namespace std;

int getLarge(vector<int>& a){
    int n=a.size();
    unordered_map<int,int>mp;
    int ans=INT_MIN;
    for(int i=0,j=0;j<n;j++){
        mp[a[j]]++;
        while(mp[a[j]]>1){
            mp[a[i]]--;
            if(mp[a[i]]==0)mp.erase(a[i]);
            i++;
        }
        if(mp.size()==(j-i+1)){
            ans=max(ans,j-i+1);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"ans:"<<getLarge(a);
}

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> b(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> b[i];
//     }

//     int v = 0;
//     int i = 0, j = 0;
//     unordered_map<int, int> k;

//     while (i < n && j < n) {
//         if (k.find(b[j]) == k.end()) {
//             k[b[j]] = j;
//             int l = j - i + 1;
//             v = max(v, l);
//             j++;
//         } else {
//             int id = k[b[j]];
//             while (i <= id) {
//                 k.erase(b[i]);
//                 i++;
//             }
//             i = id + 1;
//             k[b[j]] = j;
//             j++;
//         }
//     }

//     cout << v << endl;
//     return 0;
// }
