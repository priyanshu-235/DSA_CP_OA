#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1000000007;

struct Matrix{
    ll a[2][2];
};

Matrix multiply(Matrix A, Matrix B){
    Matrix C;
    memset(C.a,0,sizeof(C.a));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C.a[i][j]+=(A.a[i][k]*B.a[k][j])%mod;
            }
        }
    }
    return C;
}

Matrix MatPow(Matrix D, ll exp){
    Matrix K;
    K.a[0][0]=1;K.a[0][1]=0;
    K.a[1][0]=0;K.a[1][1]=1;
    while(exp>0){
        if(exp & 1 ){
             K=multiply(K,D);
        }
        D=multiply(D,D);
        exp>>=1;
    }
    return K;
}

int main(){
    ll n;
    cin>>n;
    if(n==0){cout<<0<<endl;return 0;}
    if(n==1){cout<<1<<endl;return 0;}
    //transition matrix
    Matrix M;
    M.a[0][0]=1;M.a[0][1]=1;
    M.a[1][0]=1;M.a[1][1]=0;

    Matrix Mn=MatPow(M,n-1);

    ll Fn=Mn.a[0][0]%mod;
    cout<<Fn<<endl;
    return 0;
}