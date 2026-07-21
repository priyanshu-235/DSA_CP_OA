//given an array find the subarray whose length is min and sum is >= k;
//classic two pointer-sw

#include <bits/stdc++.h>
using namespace std;

int getMinLn(vector<int>& a, int k) {
    int ans = INT_MAX;
    int n = a.size();
    int sum=0;

    for (int i=0, j = 0; j < n; j++) {
        sum+=a[j];

        // shrink window while valid
        while (sum>=k) {
            if(sum>=k)ans=min(ans,j-i+1);
            sum-=a[i];
            i++;
            
        }

    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;

    cout << "Shortest length is " << getMinLn(a, k) << endl;
}