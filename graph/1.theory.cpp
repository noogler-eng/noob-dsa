// graph

#include<iostream>
using namespace std;

// node, vertex
// any no of nodes, any no of edges (no relation)
// connected graph, disconnected graph
// no of components = no of graphs
// directed graph, undirected graph
// undirected, directed edges
// weighted graph, un weighted graph
// binary tree is directed graph (unweighted)
// a tree can be a graph but all graph is not a tree

// every tree follow this n(nodes) -> n-1(edges)
// no relation between nodes and edges in graph

// adjacency matrix (2d matrix)
// node to node edges are given in matrix (input pattern)
// marking the edge 1 which is there (it can be both direct and undirectd)

// graph can be 1 based or 0 based (there will be a seq)

// here at every index vector is stored
// list of array
// vector<int> arr[5];
// // means 1, 2, 3 ... are neigbour of 0
// // arr[0] = {1, 2, 3};

// int number_of_nodes = 5;
// int n = number_of_nodes;
// vector<int> adj[5];

// // getting all the nodes
// for(int i=0; i<n; i++){
//     cin>>u>>v;
//     // here we kepping track on undirected graph
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// // storing the weighted graphs
// int n = nodes;
// vector<pair<int, int>> adj[n];
// // getting all the nodes
// for(int i=0; i<n; i++){
//     cin>>u>>v>>wt;
//     // here we kepping track on undirected graph
//     adj[u].push_back({v, wt});
//     adj[v].push_back({u, wt});
// }

// // breadth first search (moving in level wise)
// // depth first seach (moving in depth wise)

// // conecpt of visited graph ....
// vector<int> isVisited(n, 0);
