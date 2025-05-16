// Cycle Detection in Directed Graph 
// here you can do it by both bfs and dfs as no need of the parent
// adjacent element are those who are not parent and nearby
// but there is path in multidirection so we have to take another array

#include<iostream>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &isVis, vector<int> &path){
    isVis[node] = true;
    path[node] = 1;
    
    for(auto i: adj[node]){
        if(!isVis[i]) {
            if(dfs(i, adj, isVis, path)) 
                return true;
        }else {
            if(path[i] == 1) return true;
        }
    }

    path[node] = 0;
    return false;
}

// we are considering as a 0 based indexing
bool isCyclic(vector<int> adj[], int n){
    vector<bool> isVis(n, false);
    vector<int> path(n, 0);
    for(int i=0; i<n; i++){
        if(!isVis[i]){
            if(dfs(i, adj, isVis, path)) return true;
        }
    }
    return false;
}