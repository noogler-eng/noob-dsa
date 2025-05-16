// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include<iostream>
using namespace std;

void rotate_an_matrx_by_90(vector<vector<int>> &matrix){
    // 1. transpose an matrix
    // 2. reverse an matrix
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}