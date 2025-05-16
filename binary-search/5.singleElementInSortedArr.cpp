// Single Element In Sorted Array

// You are given a sorted array consisting of only integers 
// where every element appears exactly twice, except for one 
// element which appears exactly once.

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// concept of xor, or (right and left checking) will give
// time complxity o(N)
// space complexity o(1)

// for odd, even (works on already sorted array)
// time complexity o(logN)
// space complexity o(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return nums[0];

        // Input: nums = [3,3,7,7,10,11,11]
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];

        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if((mid > 0 && nums[mid] != nums[mid-1]) && (mid < nums.size()-1 && nums[mid] != nums[mid+1])) return nums[mid];
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid+1]) low = mid + 1;
                else high = mid - 1;
            }else{
                if(nums[mid] == nums[mid-1]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};