// Search Insert Position
// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums[nums.size()-1]) return nums.size();
        if(target < nums[0]) return 0;

        int low = 0;
        int high = nums.size()-1;
        int ind = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ind = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ind;
    }
};