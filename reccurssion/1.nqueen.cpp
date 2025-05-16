// N Queen
// The n-queens puzzle is the problem of placing n queens on an n x n 
// chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
// both indicate a queen and an empty space, respectively.

#include<iostream>
using namespace std;

class Solution {
public:
    // this functionality creates an error 
    // all are the same things as we disscussed
    bool isSafe(vector<string> &board, int row, int col, int n){
        // Check left side of the row
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }


    void helper(vector<vector<string>> &places, vector<string> &board, int col, int n){
        if(col == n){
            places.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(board, i, col, n)){
                board[i][col] = 'Q';
                helper(places, board, col+1, n);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> places;
        vector<string> board(n, string(n, '.'));
        helper(places, board, 0, n);
        return places;
    }
};
