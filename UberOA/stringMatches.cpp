#include<bits/stdc++.h>
using namespace std;
struct PairHash {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1,T2>& p) const noexcept {
        std::size_t h1 = std::hash<T1>{}(p.first);
        std::size_t h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
vector<int> getMatchedArray(vector<string>& a){
    int n=a.size();
    vector<int>ans(n);
    unordered_map<pair<char,int>,int,PairHash>mp;

    for(int i=n-1;i>=0;i--){
        string s=a[i];
        int j=s.size()-1;
        int cnt=0;
        while(j>=0){
            if(mp.count({s[j],j}))cnt+=mp[{s[j],j}];
            j--;
        }
        j=s.size()-1;
        while(j>=0){
            mp[{s[j],j}]++;
            j--;
        }
        ans[i]=cnt;
    }
    return ans;
}
vector<int> getMatchedArrayWithoutCustomHash(vector<string>& a) {
    int n = a.size();
    vector<int> ans(n);
    
    // For each index position, store frequency of characters seen so far
    vector<unordered_map<char,int>> freq(1005); // assuming max string length <= 1000
    
    for (int i = n-1; i >= 0; i--) {
        string &s = a[i];
        int cnt = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            // If same char at same index appeared in later strings, add to count
            if (freq[j].count(s[j])) cnt += freq[j][s[j]];
            // Record this character at this index
            freq[j][s[j]]++;
        }
        ans[i] = cnt;
    }
    return ans;
}
vector<int>getMatchedArrayWith2d(vector<string>& a){
    int n = a.size();
    vector<int> ans(n);
    vector<vector<int>>letter(26,vector<int>(1e3,0));

    for(int i=n-1;i>=0;i--){
        string &s = a[i];
        int cnt = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            cnt+=letter[s[j]-'a'][j];
            letter[s[j]-'a'][j]++;
        }
        ans[i]=cnt;
        }
        return ans;

}
int main(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans=getMatchedArrayWith2d(a);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }
}