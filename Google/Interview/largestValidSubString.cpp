#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//function to find the largest ValidSubstring
ll largestValidSubString(string s,int k){
    multiset<char>ms;
    ll ans=0;
    for(int i=0,j=0;i<s.size();i++){
        ms.insert(s[i]);

        // while(*prev(ms.end())-*ms.begin()>k){
        //     ms.erase(ms.find(s[j]));
        //     j++;
        // }
        ll diff=*ms.rbegin()-*ms.begin();
        while(diff>k){
            ms.erase(ms.find(s[j]));
            if(!ms.empty()){
                diff=*ms.rbegin()-*ms.begin();
            }
            j++;
        }
        ll length=i-j+1;
        ans=max(ans,length);
    }
    return ans;
}

//main
int main(){

    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<"Length of Largest Valid SubString is:"<<largestValidSubString(s,k)<<endl;
    return 0;

}