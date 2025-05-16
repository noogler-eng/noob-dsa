// House Robber
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint stopping you 
// from robbing each of them is that adjacent houses have security systems connected and 
// it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum 
// amount of money you can rob tonight without alerting the police.

#include<iostream>
using namespace std;

// time complexity O(N)
// space complexity o(N)*2
class Solution {
public:
    int helper(vector<int> &nums, int i, int n, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        // if robbed
        int robbed = nums[i] + helper(nums, i+2, n, dp);
        // if not robbed
        int not_robbed = helper(nums, i+1, n, dp);
        return dp[i] = max(robbed, not_robbed);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_1(n+1, -1);
        vector<int> nums_2(n+1, -1);
        return max(helper(nums, 0, n, nums_1), helper(nums, 1, n-1, nums_2));
    }
};