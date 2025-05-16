// Search In Rotated Sorted Array
// Input: nums = [4,5,6,7,0,1,2], target = 0

#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]){
                if(target <= nums[mid] && target >= nums[low]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else if(nums[mid] <= nums[high]){
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }   
        return -1;
    }   
};