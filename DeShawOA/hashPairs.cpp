//question asks number of pair (i,j) such that |a[i]-a[j]|+|a[i]+a[j]|=target. (i,j) and (j,i) are same so you count them 1.
#include <bits/stdc++.h>
using namespace std;
// the idea is to break the formula
//C1-> both positive and a[i]>=a[j]-> a[i]=t/2; and when a[i]<a[j] it is basically the same .(no need to check) 
//so all the values that is t/2 and we have to just get the count of smaller elements of it.
//c2-> both negative-> a[j]>a[i]-> a[i]=-t/2 and when a[j]<a[i] it is same and a[i]==a[j] , a[i]=a[j]=-t/2
//so basically all the values that are -t/2 and count of values that are greater than this value. ans also equal to this value(pair to itself)
//c3-> a[i]>=0 and a[j]<0-> abs(a[i])>= abs(a[j])->a[i]=t/2 and count of negative values whose abs() value is less than equal to a[i]
// when abs(a[j])> abs(a[i])-> a[j]=-t/2 so count of the positive values whose abs() value is less than a[j]
// total six cases 

long long getCountofPairs(vector<int>& a, int target) {
    int n = a.size();
    long long ans = 0;

    int cntTargetByTwo = 0;
    int cntNegTargetByTwo = 0;
    int cntSmallerPos = 0;
    int cntGreaterNeg = 0;
    int cntNegAbsLessThanTargetByTwo = 0;
    int cntPosAbsLessThanNegTargetByTwo = 0;

    for (int x : a) {
        if (2*x == target) cntTargetByTwo++;
        if (2*x == -target) cntNegTargetByTwo++;
        if (x >= 0 && 2*x < target) cntSmallerPos++;
        if (x <= 0 && 2*x > -target) cntGreaterNeg++;
        if (x < 0 && abs(x) <= target/2) cntNegAbsLessThanTargetByTwo++;
        if (x > 0 && x <= target/2) cntPosAbsLessThanNegTargetByTwo++;
    }

    // Case 1
    ans += 1LL * cntTargetByTwo * (cntTargetByTwo - 1) / 2;
    ans += 1LL * cntTargetByTwo * cntSmallerPos;

    // Case 2
    ans += 1LL * cntNegTargetByTwo * (cntNegTargetByTwo - 1) / 2;
    ans += 1LL * cntNegTargetByTwo * cntGreaterNeg;

    // Case 3
    ans += 1LL * cntTargetByTwo * cntNegAbsLessThanTargetByTwo;
    ans += 1LL * cntNegTargetByTwo * cntPosAbsLessThanNegTargetByTwo;

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int target;
    cin >> target;
    cout << "Pairs count: " << getCountofPairs(a, target) << "\n";
    return 0;
}
