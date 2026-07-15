#include <bits/stdc++.h>
using namespace std;

int pairSum(vector<int>& a, int up,int down){
    int n=a.size();
    sort(a.begin(),a.end());
    int ansu=0;
     int i=0,j=n-1;
     while(i<j){
        if(a[i]+a[j]>up){
            j--;
        }
        else{
            i++;
            ansu++;
        }
     }
     i=0,j=n-1;
     int ansd=0;
     while(i<j){
        if(a[i]+a[j]>down){
            j--;
        }
        else{
            i++;
            ansd++;
        }
     }
     return (ansu-ansd);
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int up;
    cin>>up;
    int down;
    cin>>down;
    cout<<"ans:"<<pairSum(a,up,down-1);
}