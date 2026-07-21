//given array and k and t , in one operation you can remove maximum from the right k or left k elements 
//untill size of array becomes t
#include <bits/stdc++.h>
using namespace std;

int getCost(vector<int>& a, int k, int t) {
    int n = a.size();
    cout<<t<<" "<<endl;
    int cnt = t;
    if (cnt <= 0) return 0;

    auto cmp = [](pair<int,int> a, pair<int,int> b) {
        if (a.first != b.first) return a.first < b.first; // max-heap
        return a.second > b.second;
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> left(cmp), right(cmp);

    int l = 0, r = n - 1;
    for (int i = 0; i < k && i < n && l<r-1; i++) {left.push({a[i], i});l++;}
    for (int i = n - 1; i >= n - k && i >= 0 && r>l+1; i--) {right.push({a[i], i});r--;}

    int cost = 0;
    while (cnt--) {
        // while (!left.empty() && left.top().second < l) left.pop();
        // while (!right.empty() && right.top().second > r) right.pop(); // this is when window is shrinks to the removed index

        if (left.top().first >= right.top().first) {
            cost += left.top().first;
            left.pop();
            if (l < r-1) left.push({a[++l], l });
        } else {
            cost += right.top().first;
            right.pop();
            if (r > l+1 ) right.push({a[--r], r});
        }
        cout<<cnt<<" "<<cost<<endl;
    }
    return cost;
}
//question take just t member
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k,t;
    cin>>k>>t;

    cout << "Minimum Cost is " << getCost(a,k,t) << endl;
}
// if window size is maintained then
// int getCost(vector<int>& a, int k, int t) {
//     int n = a.size();
//     int cnt = n - t;   // number of removals
//     if (cnt <= 0) return 0;

//     auto cmp = [](pair<int,int> a, pair<int,int> b) {
//         if (a.first != b.first) return a.first < b.first; // max-heap
//         return a.second > b.second;
//     };

//     priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> left(cmp), right(cmp);

//     int l = 0, r = n - 1;
//     for (int i = 0; i < k && i < n; i++) left.push({a[i], i});
//     for (int i = n - 1; i >= n - k && i >= 0; i--) right.push({a[i], i});

//     int cost = 0;
//     while (cnt--) {
//         if (left.top().first >= right.top().first) {
//             cost += left.top().first;
//             int idx = left.top().second;
//             left.pop();
//             l = max(l, idx + 1);
//             if (l <= r && l + k - 1 <= r) left.push({a[l + k - 1], l + k - 1});
//         } else {
//             cost += right.top().first;
//             int idx = right.top().second;
//             right.pop();
//             r = min(r, idx - 1);
//             if (r >= l && r - k + 1 >= l) right.push({a[r - k + 1], r - k + 1});
//         }
//     }
//     return cost;
// }
