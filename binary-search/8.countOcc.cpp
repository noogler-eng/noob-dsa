// Count Occurrences in Sorted Array

#include<iostream>
using namespace std;

// Problem Statement: You are given a sorted array containing N integers and a number X, 
// you have to find the occurrences of X in the given array.

// time comlexity log(N) + log(M)
// space complexity o(1)
class Solution {
  public:
     int lower_bound(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int> nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }


    int countFreq(vector<int>& nums, int target) {
        // code here
        int lower_bound_val = lower_bound(nums, target);
        int upper_bound_val = upper_bound(nums, target);
        if(lower_bound_val == -1 || upper_bound_val == -1) return 0;
        return upper_bound_val - lower_bound_val + 1;
    }
};
