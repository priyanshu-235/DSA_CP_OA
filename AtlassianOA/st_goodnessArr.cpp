//given an array of integers calculate the sum of goodness of all the subarray. goodness=max element of that subarray
//contribution trick


#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>nge(vector<int>&a,int n){
    vector<pair<int,int>>ans(n);
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){st.push({a[i],i});ans[i]={-1,n};}
        else if(st.top().first>a[i]){ans[i]=st.top();st.push({a[i],i});}
        else{
            while(!st.empty() && a[i]>=st.top().first){
                //cout<<a[i]<<" idx "<<i<<" popped "<<st.top().first<<" idx "<<st.top().second<<endl;
                st.pop();}
            if(st.empty()){st.push({a[i],i});ans[i]={-1,n};}
            else {ans[i]=st.top();st.push({a[i],i});}
        }
        // cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return ans;
}
vector<pair<int,int>>pge(vector<int>&a,int n){
    vector<pair<int,int>>ans(n);
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        if(st.empty()){st.push({a[i],i});ans[i]={-1,-1};}
        else if(st.top().first>a[i]){ans[i]=st.top();st.push({a[i],i});}
        else{
            while(!st.empty() && a[i]>=st.top().first){
                //cout<<a[i]<<" idx "<<i<<" popped "<<st.top().first<<" idx "<<st.top().second<<endl;
                st.pop();}
            if(st.empty()){st.push({a[i],i});ans[i]={-1,-1};}
            else {ans[i]=st.top();st.push({a[i],i});}
        }
        // cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
    vector<pair<int,int>>ngeArr=nge(a,n);
    vector<pair<int,int>>pgeArr=pge(a,n);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(1LL*a[i]*(i-pgeArr[i].second)*(ngeArr[i].second-i));
    }
    cout<<"Total goodNess:"<<ans<<endl;
    return 0;
}
// 8
// 5 6 3 4 7 2 4 5