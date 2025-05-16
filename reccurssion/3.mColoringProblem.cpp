// M Coloring Problem

#include<iostream>
using namespace std;

// Given an undirected graph and a number m, determine if the graph can be colored with at most m colors 
// such that no two adjacent vertices of the graph are colored with the same color.
bool isSafe(int node, vector<int> &colors, int n, vector<vector<int>> &mat, int col){
    // moving to add its adjacent colors and checking if they are matching or not
    // if adjacent colors are matching then return false
    for(int i=0; i<n; i++){
        if(mat[node][i] == 1 && colors[i] == col) return false;
    }
    return true;
}


bool helper(int node, vector<vector<int>> &mat, int m, int n, vector<int> &colors){
    if(node == n) return true;

    // when to use backtracking
    // for each and every node we can color from 1 -> m
    // checking first is it safe to color
    for(int i=1; i<=m; i++){
        if(isSafe(node, colors, n, mat, i)){
            colors[node] = i;
            if(helper(node + 1, mat, m, n, colors) == true) return true;
            colors[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> colors(mat.size()+1, 0);
    if(helper(0, mat, m, n, colors) == true) return "YES";
    else return "NO";
}