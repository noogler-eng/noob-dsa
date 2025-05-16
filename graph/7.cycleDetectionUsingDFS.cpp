// Cycle Detection Using DFS 
#include<iostream>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &isVis){
    isVis[node] = true;
    for(auto i: adj[node]){
        if(!isVis[i]) if(dfs(i, node, adj, isVis)) return true;
        else if(i != parent) return true;
    }
    return false;

}

// time complexity o(V+E)
// space complexity o(V)
// cycle detection in graph using BFS
// consider a 0 based indexing graph
bool isCyclePresent(vector<int> adj[], int node, int n){
    vector<bool> isVis(n, false);
    if(dfs(0, -1, adj, isVis)) return true;
    return false;
}