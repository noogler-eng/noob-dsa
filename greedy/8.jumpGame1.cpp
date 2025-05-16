// Jump Game 1

#include<iostream>
using namespace std;

// Input:nums = [2, 3, 1, 0, 4]
// [2, 3, 1, 1, 4]
// important questions ----

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if(i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1) return true;
        }
        return false;
    }
};