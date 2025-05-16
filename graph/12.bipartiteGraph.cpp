// Graph bipartite means it can be colored with y, b and it is of even length
// Graph can be non bipartite when its length is odd

// how we can check if graph is bipartite or not
// by coloring y and b
// if there is same color neaby then non bipartite

#include<iostream>
using namespace std;

void dfs(vector<int> adj[], vector<int> &color, int node, int col){
    color[node] = col;
    for(auto i: adj[node]){
        if(color[i] == col) return false;
        else if(color[i] == -1){
            if(!dfs(adj, color, i, 1 - col)) return false;
        }
    }
    return true;
}

bool isBipartiteGraph(vector<int> adj[], int n){
    // -1 means it is not visited
    // 1 means it is colored with blue
    // 0 means it is colored with green
    vector<int> color(n, -1);
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            // starting with color 0
            if(!dfs(adj, color, i, 0)) return false;
        }
    }
    return true;
}
