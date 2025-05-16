#include<iostream>
using namespace std;

// DFS traversal
void dfs(int node, vector<int> &isVis, vector<int> arr[]){
    isVis[node] = 1;
    for(auto i: arr[node]){
        if(isVis[i] != 1){
            dfs(i, isVis, arr);
        }
    }
}

void dfs_traversal(vector<int> arr[], int n){
    vector<int> isVis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(isVis[i] != 1){
            dfs(i, isVis, arr);
        }
    }
}



// this is the BFS traversal
void bfs(vector<int> arr[], vector<int> &isVis, int node){
    queue<int> q;
    q.push(node);
    isVis[node] = 1;
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<endl;
        q.pop();

        for(auto i: arr[curr]){
            if(!isVis[i]){
                isVis[i] = 1;
                q.push(i);
            }
        }
    }
    return;
}

// bfs traversal
// queue has been used here
void bfs_traversal(vector<int> arr[], int n){
    vector<int> isVis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!isVis[i]){
            bfs(arr, isVis, i);
        }
    }
    return;
}