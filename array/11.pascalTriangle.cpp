// Pascal's triangle

// Problem Statement: This problem has 3 variations. They are stated below:
// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle

// Example 1:
// Input Format: N = 5, r = 5, c = 3
// Result: 6 (for variation 1)
// 1 4 6 4 1 (for variation 2)

// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1    (for variation 3)

// here anywhere the any colom and row value will be (n-1) c (r-1) where n is row and r is coloumn

#include<iostream>
using namespace std;
int get_specifc_value(int specific_row, int specific_col){
    int row = specific_row - 1, col = specific_col - 1;
    int value = 1;
    // let say 5c3 then 5 * 4 / 2 * 1

    for(int i=row; i>col; i++){
        value = value * i;
        value = value / (i - col);
    }
    return value;
}   
