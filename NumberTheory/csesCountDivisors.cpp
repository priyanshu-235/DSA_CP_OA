// given n integers return their count of divisors
#include <bits/stdc++.h>
using namespace std;

const int MAX=1e7;
vector<int> precompute(){
    vector<int>sieve(MAX+1,0);
    sieve[0]=sieve[1]=0;
    sieve[2]=2;
    for(int i=4;i<MAX+1;i+=2){
         sieve[i]=2;
    }
    for(int i=3;i<MAX+1;i+=2){
        if(sieve[i]==0){
            sieve[i]=i;
            for(long long j=(long long)i*i; j<MAX+1; j+=2*i){
                sieve[j]=(int)i;
            }
        }
    }
    return sieve;
}
long long getDivisorsCount(int x, vector<int>& sieve){
    long long ans = 1;
    while (x > 1) {
        int spf = sieve[x];
        int exponent = 0;
        while (x % spf == 0) {
            x /= spf;
            exponent++;
        }
        ans *= (exponent + 1);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>sieve=precompute();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cout<<getDivisorsCount(x,sieve)<<endl;
        
    }
    return 0;
}