// FrogJump
#include<iostream>
using namespace std;

// time complexity o(2^N)
// space complexiyt o(N)
// for optmisation use vector / dp
int helper(vector<int> &heights, int n){
    if(n == 0) return 0;
    int mini = INT_MAX;
    if(n-1 >= 0){
        int fromSecond = abs(heights[n] - heights[n-1]) + helper(heights, n-1);
        mini = min(mini, fromSecond);
    }

    if(n-2 >= 0){
        int fromThird = abs(heights[n] - heights[n-2]) + helper(heights, n-2);
        mini = min(mini, fromThird);
    }

    return mini;
}

int frogJump(int n, vector<int> &heights){
    return helper(heights, n-1);
}