//given n find nth prime n can be upto 5*10^5
//so, from n/ln(n)-> we can find that 1e7 could be a range in between which max prime can come
// 🔑 Why we only go up to √n
// When you’re marking multiples in the sieve, you don’t need to check primes beyond √n because:
// Suppose you’re at a prime p.
// If p > √n, then p * p > n.
// That means any composite number ≤ n must already have been marked by a smaller prime factor.
// In other words:
// Every composite number ≤ n has at least one prime factor ≤ √n.
// So once you’ve crossed √n, all remaining numbers that are still marked as prime are indeed prime — no further marking is needed.

#include <bits/stdc++.h>
using namespace std;
int MAX=1e7;
vector<int>sieve(MAX+1,1);
void precompute(){
    for(int i=4;i<MAX+1;i+=2){
         sieve[i]=0;
    }
    for(int i=3;i<MAX+1;i+=2){
        if(sieve[i]){
            for(int j=i*i;j<MAX+1;j+=2*i){
                sieve[i]=0;
            }
        }
    }
}


int main(){
    int n;
    cin>> n;
    precompute();
    int cnt=0;
    for(int i=2;i<MAX+1;i++){
       if(sieve[i]){
        cnt++;
       }
       if(cnt==n){
        cout<<i<<endl;
        break;
       }
    }
    return 0;
}