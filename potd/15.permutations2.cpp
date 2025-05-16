// Permutations - 2
// Given a collection of numbers, nums, that might contain 
// duplicates, return all possible unique permutations in any 
// order.

#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int n, int index) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<char> used;
        for (int i = index; i < n; i++) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[index], nums[i]);
            helper(nums, ans, n, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        helper(nums, ans, n, 0);
        return ans;
    }
};