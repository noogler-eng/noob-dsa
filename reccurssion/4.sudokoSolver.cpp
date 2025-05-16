// Sudoko Solver

// Given a 9x9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.
// 1. All the rows should be filled with numbers(1 - 9) exactly once.
// 2. All the columns should be filled with numbers(1 - 9) exactly once.
// 3. Each 3x3 submatrix should be filled with numbers(1 - 9) exactly once.
// Note: Character '.' indicates empty cell

#include<iostream>
using namespace std;
bool isSafe(vector<vector<int>>& sudoku, int x, int y, int num){
    for(int i=0; i<sudoku.size(); i++){
        if(sudoku[i][y] == num) return false;
    }

    for(int i=0; i<sudoku[0].size(); i++){
        if(sudoku[x][i] == num) return false;
    }

    // now checking for qudrat
    // we have to checking in respective qudarnat like 
    // 3 * 3 ....
    // here 3 * X is starting point of that qudrant (in row)
    // here 3 * Y is the starting point of that qudrant (in col)
    int X = (x / 3) * 3;
    int Y = (y / 3) * 3;
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if(sudoku[X + i][Y + j] == num) return false;
        }
    }

    return true;
}

bool helper(vector<vector<int>>& sudoku, int n, int m, int i, int j){
    if(i == 9) return true;
    if(j == 9) return helper(sudoku, n, m, i + 1, 0);
    if(sudoku[i][j] != 0) return helper(sudoku, n, m, i, j+1);

    for(int num=1; num<=9; num++){
        if(isSafe(sudoku, i, j, num)){
            sudoku[i][j] = num;
            if(helper(sudoku, n, m, i, j + 1)) return true;
            sudoku[i][j] = 0;
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>>& sudoku){
    int n = sudoku.size();
    int m = sudoku[0].size();
    helper(sudoku, n, m, 0, 0);
}