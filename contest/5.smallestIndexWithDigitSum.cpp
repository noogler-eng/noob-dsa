// Smallest Index With Digit Sum equals index
// https://leetcode.com/contest/weekly-contest-450/problems/smallest-index-with-digit-sum-equal-to-index/?slug=minimum-swaps-to-sort-by-digit-sum&region=global_v2
#include<iostream>
using namespace std;

// time complexity o(N*M)
// space complexity o(1)
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            int temp = nums[i];
            while(temp > 0){
                sum += temp % 10;
                temp = temp / 10;
            }
            if(sum == i) return i;
        }  
        return -1;
    }
};