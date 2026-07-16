/// given a array of size N and and L and R find the min length of subarray which contains every value from L to R (inclusive)
#include <bits/stdc++.h>
using namespace std;

int getMinLn(vector<int>& a, int L, int R) {
    unordered_map<int,int> mp;
    int ans = INT_MAX;
    int n = a.size();
    int i = 0;

    for (int j = 0; j < n; j++) {
        if (a[j] >= L && a[j] <= R) mp[a[j]]++;

        // shrink window while valid
        while (mp.size() == (R - L + 1)) {
            ans = min(ans, j - i + 1);

            if (a[i] >= L && a[i] <= R) {
                mp[a[i]]--;
                if (mp[a[i]] == 0) mp.erase(a[i]);
            }
            i++;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int L, R;
    cin >> L >> R;

    cout << "Shortest length is " << getMinLn(a, L, R) << endl;
}

// #include <bits/stdc++.h>
// using namespace std;


// int getMinLn(vector<int>& a, int L, int R){
//    unordered_map<int,int>mp;
//    int ans=INT_MAX;
//    int n=a.size();
//    for(int i=0,j=0;j<n;j++){

//     if(a[j]>=L && a[j]<=R)mp[a[j]]++;

//     if(mp.size()==(R-L+1)){
//       ans=min(ans,j-i+1);


//       if(a[i]<=R && a[i]>=L){
//         mp[a[i]]--;
//         if(mp[a[i]]==0)mp.erase(a[i]);
//       }
//       i++;

//       if(a[j]>=L && a[j]<=R){mp[a[j]]--;j--;}// this part is to check i+1...j because i+1..j-1 is invalid
//     }

   

// }

//     return ans==INT_MAX?-1:ans;
// }



// int main(){
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];

//     }
//     int L,R;
//     cin>>L>>R;
//     cout<<"Shortest length is "<<getMinLn(a,L,R)<<endl;
// }