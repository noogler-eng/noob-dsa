// Find The Peak Element

#include<iostream>
using namespace std;
// Input: nums = [1,2,1,3,5,6,4]
// we have to find the peak element
// peak element > left and > right

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;

        int low = 1;
        int high = nums.size()-2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }

        return -1;
    }
};