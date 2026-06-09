// This question says N male and N female penguines are their. for pairing if anyones height is given as negative it means it will require a shorter height of penguin from opposite gender only. and if Positive then higher.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // number of male and female penguins

    vector<ll> malePos, maleNeg, femalePos, femaleNeg;

    // male penguins
    for (int i = 0; i < n; i++) {
        ll h; cin >> h;
        if (h > 0) malePos.push_back(h);
        else if (h < 0) maleNeg.push_back(abs(h));
    }

    // female penguins
    for (int i = 0; i < n; i++) {
        ll h; cin >> h;
        if (h > 0) femalePos.push_back(h);
        else if (h < 0) femaleNeg.push_back(abs(h));
    }

    // Sort descending
    sort(malePos.rbegin(), malePos.rend());
    sort(maleNeg.rbegin(), maleNeg.rend());
    sort(femalePos.rbegin(), femalePos.rend());
    sort(femaleNeg.rbegin(), femaleNeg.rend());

    auto countPairs = [&](vector<ll>& A, vector<ll>& B) {
        int i = 0, j = 0;
        int cnt = 0;
        while (i < (int)A.size() && j < (int)B.size()) {
            if (A[i] < B[j]) { // A wants taller, B wants shorter
                cnt++;
                i++; j++;
            } else {
                i++;
            }
        }
        return cnt;
    };
    
    for( int i=0;i<malePos.size();i++){
        cout<<malePos[i]<<" \n"[i==malePos.size()-1];
    }
    
    for( int i=0;i<femaleNeg.size();i++){
        cout<<femaleNeg[i]<<" \n"[i==femaleNeg.size()-1];
    }
    
    for( int i=0;i<femalePos.size();i++){
        cout<<femalePos[i]<<" \n"[i==femalePos.size()-1];
    }
    
    for( int i=0;i<maleNeg.size();i++){
        cout<<maleNeg[i]<<" \n"[i==maleNeg.size()-1];
    }
    // Male positive vs Female negative
    int pairs1 = countPairs(malePos, femaleNeg);
    // Female positive vs Male negative
    int pairs2 = countPairs(femalePos, maleNeg);
    cout<<pairs1<<" "<<pairs2<<endl;

    cout << (pairs1 + pairs2) << "\n";
    return 0;
}
