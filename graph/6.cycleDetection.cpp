// Cycle Dectection
// directed, undirected graph
// using bfs abd dfs

// cycle -> if we move back to same element (visited)
// for cycle the prev node which is visited and not a parent of curr node

#include<iostream>
using namespace std;

// time complexity o(V+E)
// space complexity o(V)
// cycle detection in graph using BFS
bool isCyclePresent(vector<int> adj[], int node, int n){
    vector<int> vis(n+1, 0);
    queue<pair<int, int>> q;
    vis[node] = 1;
    q.push({node, -1});
    
    while(!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto i: adj[curr]){
            if(!vis[i]) {
                vis[i] = 1;
                q.push({i, curr});
            }
            else if(i != parent) return true;
        }
    }

    return false;
}