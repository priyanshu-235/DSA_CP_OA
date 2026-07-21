
#include<bits/stdc++.h>
using namespace std;
//Priority Queue
//priority queue expects true if you want to swap , so what you want you right opposite of it
priority_queue<int> pq; // uses std::less<int>
priority_queue<int, vector<int>, greater<int>> pq;
struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second) return a.first > b.first; 
        return a.second > b.second; 
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
auto cmp = [](pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
};

priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
