// question given a query and a price array-> goal is to make each price equal to the query[i]. find ops to do that for each query. ops- +1 or -1 of any one price.

//solution-> sort the arr-> take a prefix sum-> now for each query-> find max i for which arr[i]<query[k]-> BS now the answer-> (i+1)*query[k]-prefix[i]+ (prefix[n]-prefix[i])(n-i)*query[k]
#include<bits/stdc++.h>
using namespace std;

int findMaxIdx(int a,int n,vector<int>& arr){
    int low=0, high=n-1,mid,ans=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]>a){
            high=mid-1;
        }
        else{
         low=mid+1;
         ans=mid;
        }
    }
    return ans;
}
void opstoEqualize(int n, vector<int>&arr, int q, vector<int>& query){
          sort(arr.begin(),arr.end());
          vector<int>prefix(n+1,0);
         //prefix
         for(int i=1;i<=n;i++){
            prefix[i]=arr[i-1]+prefix[i-1];
         }
         for(int i=0;i<q;i++){
            int idx=findMaxIdx(query[i],n,arr);
            long long ans = (long long)(idx+1)*query[i] - prefix[idx+1]
            + (prefix[n] - prefix[idx+1]) - (long long)(n - idx - 1)*query[i];

            cout<<ans<<" \n"[i==q-1];
         }
}


int main(){
    int n,q;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>q;
    vector<int>query(q);
    for(int i=0;i<q;i++){
        cin>>query[i];
    }
    opstoEqualize(n,arr,q,query);
    return 0;
}