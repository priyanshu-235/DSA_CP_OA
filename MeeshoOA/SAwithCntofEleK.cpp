//given a subarray count the number of subarrays which has cnt of each element equal to k
//only 0-9 values are given

#include <bits/stdc++.h>
using namespace std;
bool check(unordered_map<int,int>& mp,int k){
    for(auto pair:mp){
        if(pair.second!=k)return false;
    }
    return true;
}
// int getCntSA(vector<int>& a, int k) {
//     unordered_map<int,int>mp;
//     int ans = 0;
//     int n = a.size();   this method is not valid because shrinking doesn't ensure that you will check 
// all the valid subarrays because of that exact k. you are assuming when >k then you are shrinking if <=k then 
// it would have worked. example-> [1 1 1 2 2] k=2, it misses -> 1,2 / 2 2

//     for (int i=0, j = 0; j < n; j++) {
//         mp[a[j]]++;

//         // shrink window while valid
//         while (mp[a[j]]>k) {
//             mp[a[i]]--;
//             i++;        
//         }
//       if(check(mp,k))ans++;

//     }

//     return ans;
// }
// the question can be done in other way also...the possible sizes could be k,2k,3k,4k,...10k max 10 values
//so for each k run a sliding window and check map
int getCntSA(vector<int>& a, int k) {
    int n = a.size();
    int ans = 0;

    for (int m = 1; m <= 10; m++) {
        int L = m * k;
        if (L > n) break;

        vector<int> freq(10, 0);
        int distinct = 0;

        // first window
        for (int i = 0; i < L; i++) {
            if (freq[a[i]] == 0) distinct++;
            freq[a[i]]++;
        }
        auto valid = [&]() {
            for (int x = 0; x < 10; x++) {
                if (freq[x] != 0 && freq[x] != k) return false;
            }
            return true;
        };
        if (valid()) ans++;

        // slide window
        for (int i = L; i < n; i++) {
            freq[a[i-L]]--;
            if (freq[a[i-L]] == 0) distinct--;
            if (freq[a[i]] == 0) distinct++;
            freq[a[i]]++;

            if (valid()) ans++;
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;

    cout << "Shortest length is " << getCntSA(a, k) << endl;
}