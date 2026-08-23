//given two arrays you have two option either go to i+1 of same array or another array. count number of odd journeys and even journeys
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

pair<int,int> cntOddJourney(int n, vector<int>& A, vector<int>& B){
    
    vector<vector<int>>dpa(2,vector<int>(n));
    vector<vector<int>>dpb(2,vector<int>(n));

    //dp[0][i]-> number of journeys that are odd till i
    //dp[1][i]-> number of journey that are even till i
    dpa[0][0]=(A[0]%2==1?1:0);
    dpa[1][0]=(A[0]%2==0?1:0);
    dpb[0][0]=(B[0]%2==1?1:0);
    dpb[1][0]=(B[0]%2==0?1:0);

    for(int i=1;i<n;i++){
        
        if(A[i]%2==1){
            dpa[0][i]=dpa[1][i-1]+dpb[1][i-1];
            dpa[1][i]=dpa[0][i-1]+dpb[0][i-1];
        }
        else{
            dpa[0][i]=dpa[0][i-1]+dpb[0][i-1];
            dpa[1][i]=dpa[1][i-1]+dpb[1][i-1];
        }
        if(B[i]%2==1){
            dpb[0][i]=dpb[1][i-1]+dpa[1][i-1];
            dpb[1][i]=dpb[0][i-1]+dpa[0][i-1];
        }
        else{
            dpb[0][i]=dpb[0][i-1]+dpa[0][i-1];
            dpb[1][i]=dpb[1][i-1]+dpa[1][i-1];
        }

    }
    return {dpa[0][n-1]+dpb[0][n-1],dpa[1][n-1]+dpb[1][n-1]};
}


int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    vector<int>B(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    pair<int,int> r=cntOddJourney(n,A,B);
    cout<<"odd Journeys:"<<r.first<<" Even Journeys:"<<r.second<<endl;
    return 0;
}