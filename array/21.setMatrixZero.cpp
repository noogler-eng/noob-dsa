// Set Matrix Zero
// Problem Statement: Given a matrix if an element in the matrix is 0 
// then you will have to set its entire column and row to 0 and then return the matrix.

// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// we have to make whole col and row to be 0 which consists of 0 iniially
#include<iostream>
using namespace std;

class Solution {
public:
    void makeCol(vector<vector<int>>& mat, int col) {
        for (int i = 0; i < mat.size(); i++)
            if(mat[i][col] != 0) {
                mat[i][col] = INT_MIN/2;
            }
    }

    void makeRow(vector<vector<int>>& mat, int row) {
        for (int i = 0; i < mat[0].size(); i++)
            if(mat[row][i] != 0){
                mat[row][i] = INT_MIN/2;
            }
    }

    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    makeRow(mat, i);
                    makeCol(mat, j);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == INT_MIN/2){
                    mat[i][j] = 0;
                }
            }
        }

        return ;
    }
};


// optmized version and more clear
// time complexity o(N) * 2
// space complexity o(N*M)
void make_matrix_zero(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, -1);
    vector<int> col(m, -1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] == 0 || col[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
}