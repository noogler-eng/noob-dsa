// Spiral Traversal of Matrix

// Input: Matrix[][] = { { 1, 2, 3, 4 },
// 		      { 5, 6, 7, 8 },
// 		      { 9, 10, 11, 12 },
// 	              { 13, 14, 15, 16 } }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

#include<iostream>
using namespace std;

vector<int> print_matrix_in_spiral_form(vector<vector<int>> &matrix){
    int left = 0, right = matrix[0].size()-1;
    int top = 0, bottom = matrix.size()-1;
    vector<int> temp;
    while(left <= right && top <= bottom){
        if(left <= right && top <= bottom){
            for(int i=left; i<=right; i++){
                temp.push_back(matrix[top][i]);
            }
            top++;
        }

        if(top <= bottom && left <= right){
            for(int i=top; i<=bottom; i++){
                temp.push_back(matrix[i][right]);
            }
            right--;
        }

        if(left <= right && top <= bottom){
            for(int i=right; i>=left; i--){
                temp.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(top <= bottom && left <= right){
            for(int i=bottom; i>=top; i--){
                temp.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return temp;
}