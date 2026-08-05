//given an array consisting of integers, the productSum is defined as a[i]*i. now what you can do is you can take any subsequence and rearrange them
//in any order. find the max ProdSum.


// the obs-> positive numbers will always be there.now min number should be multiplied with min indexes. some times taking zero/negative in 
//the subsequence will increase the sum as it is product sum with index.
//we will try out all possibilities.
// all pos -> 0 -ve + 1 0 + all pos.... like that

#include<bits/stdc++.h>
using namespace std;


int getMaxProdSum(vector<int>&a,int n, int Sum){
   sort(a.begin(),a.end());
   int i=0,j=0;
   while(j<n && a[j]<=0){
    j++;
   }
   i=j;
   int ans=INT_MIN;
   int curProdSum=0;
   int idx=1;
   while(i<n){
    curProdSum+=(idx*a[i]);
    idx++;
    i++;
   }
   ans=max(curProdSum,ans);
   while(j>0){
     j--;
     Sum+=a[j];
     curProdSum+=Sum;
     ans=max(curProdSum,ans);
   }
   return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int Sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)Sum+=a[i];
    }
    cout<<"ans:"<<getMaxProdSum(a,n,Sum)<<endl;
}