//  Maximum sum of non-adjacent elements

#include<iostream>
using namespace std;

// time complexiyt o(2^N)
// space compleity o(N) + o(N) for stack space
int helper(vector<int> &nums, int i, int n, vector<int> &dp){
    if(i > n) return 0;
    if(dp[i] != -1) return dp[i];

    int taking = nums[i] + helper(nums, i+2, n, dp);
    int not_taking = helper(nums, i+1, n, dp);
    return dp[i] = max(taking, not_taking);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return helper(nums, 0, n-1, dp);
}