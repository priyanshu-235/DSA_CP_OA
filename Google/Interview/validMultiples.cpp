#include<bits/stdc++.h>
using namespace std;
int validMultiples(int N, vector<int>& A, int M, vector<int>& B){
    unordered_map<int,int>HmpA;
    unordered_map<int,int>HmpB;
    int totalCnt=0;
    for(int i=0;i<N;i++){
        HmpA[A[i]]++;
    }
    for(int i=0;i<M;i++){
        HmpB[B[i]]++;
    }
    for(auto pair:HmpA){
       for(int i=pair.first;i<1e6;i+=pair.first){
        if(HmpB.count(i))
        totalCnt+=pair.second*HmpB[i];
       }
    }
    return totalCnt;
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<int>A(N);
    vector<int>B(M);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
    cout<<"Count of valid pairs is: "<<validMultiples(N,A,M,B)<<endl;
    return 0;

}