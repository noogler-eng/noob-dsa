// Toposort
// arragment of the element in such a way that a commes first then b
// is a -> b ...

// ways of doing the toposort
// - khan's alsogirthm (BFS) 
// - DFS (stack + vector)

#include<iostream>
using namespace std;

// toposort is only working for DAG (directed acyclic graph)
// finding indegress for a graph
// assuming 0 based indexing graph, it cn only happens in directed graph
// time complexity o(V+E)
// space complexity o(1) not including the ans vector
vector<int> finding_indegrees(vector<int> adj[], int n){
    vector<int> indeg(n, 0);
    for(int i=0; i<n; i++){
        for(auto j: adj[i]){
            indeg[j]++;
        }
    }
    return indeg;
}


// DFS
// here we will move at the last node and push it into the stack
// we are assuming it is 1 based indexing
// time complexity o(N) approax
// time complexity o(V+E)
// space complexity o(v+E)
void dfs(int node, vector<int> adj[], vector<bool> &isVis, stack<int> &st){
    isVis[node] = true;
    for(auto i: adj[node]){
        if(!isVis[i]){
            dfs(i, adj, isVis, st);
        }
    }
    st.push(node);
}

vector<int> toposort_tarversal(vector<int> adj[], int n){
    stack<int> st;
    vector<int> toposort;
    vector<bool> isVis(n, false);
    for(int i=0; i<n; i++){
        if(!isVis[i]){
            dfs(i, adj, isVis, st);
        }
    }

    while(!st.empty()){
        toposort.push_back(st.top());
        st.pop();
    }

    return toposort;
}


// khan's algorithm
// it is nows for BFS
// time complexiyt o(V + E)
// space complexity o(2N) as not including the ans vector
vector<int> toposort(vector<int> adj[], int n){
    vector<int> indeg(n+1, 0);
    vector<int> ans;
    // time complexity o(V + E)
    for(int i=1; i<=n; i++){
        for(auto j: adj[i]){
            indeg[j]++;
        }
    }

    // push all the elements which has the 0 indeg
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto i: adj[node]){
            indeg[i]--;
            if(indeg[i] == 0) q.push(i);
        }
    }

    return ans;
}
