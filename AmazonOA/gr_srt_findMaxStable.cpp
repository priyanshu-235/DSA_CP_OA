//given two arrays A and R , find the max value of S, where S=min(A[i])*sum(R[i])-> that is the chosen i to j could be subsequence not subset.

#include <bits/stdc++.h>
using namespace std;


int getMaxStable(const vector<int>& A, const vector<int>& R, int n){
    vector<pair<int,int>>S(n);
    for(int i=0;i<n;i++){
        S[i]={A[i],R[i]};
    }
    sort(S.begin(),S.end());

    int Psum=0,Nsum=0;
    int ans=INT_MIN;
    for(int i=n-1;i>=0;i++){
        if(S[i].second>0)Psum+=S[i].second;
        else Nsum+=S[i].second;
        if(S[i].first>0){
           ans=max(ans,S[i].first*Psum);

        }
        else{
            ans=max(ans,S[i].second*Nsum);
        }
     return ans;

    }
}

int main() {
	int n;cin>>n;
    vector<int> A(n);
    vector<int>R(n);
    for(int i=1;i<=n;i++){
    	cin>>A[i-1];
    }
    for(int i=0;i<n;i++){
       cin>>R[i];
    }
    cout<<getMaxStable(A,R,n);
    return 0;
}

