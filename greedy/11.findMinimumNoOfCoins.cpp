// Find minimum number of coins
// Problem Statement: Given a value V, if we want to make a change for V Rs, 
// and we have an infinite supply of each of the denominations in Indian currency, i.e., 
// we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
// what is the minimum number of coins and/or notes needed to make the change.

#include<iostream>
using namespace std;

// { 1, 2, 5, 10, 20, 50, 100, 500, 1000}
// Input: V = 70

int minimum_no_of_coins(vector<int> exchanges, int value){
    int i=exchanges.size()-1, count = 0;
    while(value > 0 && i >= 0){
        if(exchanges[i] > value){
            i--;
        }else{
            value = value - exchanges[i];
            count++;
        }
    }

    if(value != 0) return -1;
    return count;
}