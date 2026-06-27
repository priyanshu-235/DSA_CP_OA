// In this problem an undirected graph of N nodes and M edges are given , unweighted-> find the shortest path for each node with max 5s

#include<bits/stdc++.h>
using namespace std;

void findShortestPathWithMaxValue(vector<int>G[],int N,vector<int>& Value){
  vector<int>visited(N,0);
  vector<int>shortest(N,0);
  vector<int>fiveCount(N,0);
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
        // start a new BFS for this component
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        shortest[i] = 0;
        fiveCount[i] = Value[i] == 5 ? 1 : 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : G[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                    shortest[neighbor] = shortest[node] + 1;
                    fiveCount[neighbor] = Value[neighbor] == 5 ? fiveCount[node] + 1 : fiveCount[node];
                } 
                else if (shortest[node] + 1 == shortest[neighbor]) {
                    int currFiveCnt = Value[neighbor] == 5 ? fiveCount[node] + 1 : fiveCount[node];
                    fiveCount[neighbor] = max(fiveCount[neighbor], currFiveCnt);
                }
            }
        }
    }
}

    for(int i=0;i<N;i++){
        cout<<"Shortest path length: "<<shortest[i]<<" fiveCount: "<<fiveCount[i]<<endl;
    }
  }

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> G[N];
    vector<int>Value(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<N;i++){
        cin>>Value[i];
    }
   cout<<"shortest path for each node from source node: "<<endl;
   findShortestPathWithMaxValue(G,N,Value);
   return 0;
}