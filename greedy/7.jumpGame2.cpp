// Jump Game 2

#include<iostream>
using namespace std;

// Input: nums = [2,3,1,1,4]
// minimum no of jumps so that we can reach at last
// important
// [2,3,1,1,4]
// [2,3,0,1,4]

class Solution {
public:
    // we should awlays taking care of maxi one
    // searching for the farthest one 
    int jump(vector<int>& nums) {
        int no_of_jump = 0;
        int curr = 0;
        int farthest = 0;

        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == curr){
                no_of_jump++;
                curr = farthest;
            }
        }
        return no_of_jump;
    }
};