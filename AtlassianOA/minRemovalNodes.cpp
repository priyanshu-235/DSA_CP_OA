// Given N islands with importance values A[i], all initially connected. Destroying a bridge between islands i and j costs A[i] * A[j].
// Alex can destroy bridges with total cost ≤ C to minimize the number of islands reachable from island 1.
// Find the minimum number of islands (including island 1) that remain connected to island 1 after optimal destruction.

// so in order to minimize the nodes I have to remove maximum amount of nodes from the network. And to remove max num of nodes I have to take out
// those nodes which has min cost while removing because I have a constraint of C(max cost to be deducted).
// so , for 1 node removal-> the cost will be a[i]*a[k1]+a[i]*a[k2]+...for k!=i=a[i]*(sum of other nodes)
// for 2 node removal-> cost will be (a[i]+a[j])*(sum of other nodes)-> we can represent this as y*(total_cost-y)-> this is minimum at y=0,total_cost
// so to minimize cost-> we have to take the largest values or smallest values.ex- for 1 node removal-> sorted array-> first or last 
// for 2 node removal-> first two or last two and so on. 
// now for each n I will check cost<=c if yes then forward.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t; cin >> t;
    while(t--){
        ll n, c; cin >> n >> c;
        vector<ll> b(n+1);
        ll sum = 0;
        for(ll i=1; i<=n; i++){
            cin >> b[i];
            sum += b[i];
        }

        // sort all except island 1
        sort(b.begin()+2, b.end());

        ll answer = 0;
        ll prefixSum = 0;   // running sum of smallest group
        ll suffixSum = 0;   // running sum of largest group

        for(ll do_it=1; do_it<=n-1; do_it++){
            // add next smallest
            prefixSum += b[1+do_it];   // because smallest group starts at b[2]
            ll costSmall = (sum - prefixSum) * prefixSum;

            // add next largest
            suffixSum += b[n-do_it+1];
            ll costLarge = (sum - suffixSum) * suffixSum;

            ll u1 = min(costSmall, costLarge);

            if(u1 <= c) answer = do_it;
        }

        cout << n - answer << "\n";
    }
}
