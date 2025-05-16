// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique 
// triplets that add up to give a sum of zero. In short, you need to return an 
// array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, 
// and their sum is equal to zero.

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(1) without including ans vector
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        // should the array should be shorted
        sort(nums.begin(), nums.end());

        // trying out with every low ....
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // this is the first element
            int low = i + 1;
            int high = nums.size() - 1;

            while (low < high) {
                // here we are summing up all the three elements
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while(low < high && nums[low] == nums[low-1]) low++;
                } else if (sum > 0) {
                    high--;
                    // this will work until low < high
                    while (low < high && high + 1 < nums.size() && nums[high] == nums[high + 1]) high--;
                } else {
                    low++;
                    // this will work until low < high
                    while (low < high && low - 1 > 0 && nums[low] == nums[low - 1]) low++;
                }
            }
        }
        return ans;
    }
};