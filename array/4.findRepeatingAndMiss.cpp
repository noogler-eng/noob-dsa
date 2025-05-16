// Find the repeating and missing number
// Problem Statement: You are given a read-only array of N integers with values 
// also in the range [1, N] both inclusive. Each integer appears exactly once 
// except A which appears twice and B which is missing. 
// The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

#include<iostream>
using namespace std;

// Input Format:  array[] = {3,1,2,5,3}
// Result: {3,4)
// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing
// time complexity o(N) * 2
// space complexity o(1)
pair<int, int> find_missing_and_repeating(vector<int> nums){
    int missing;
    int repeating;
    for(int i=0; i<nums.size(); i++){
        // as number are from 1 to N
        int index = abs(nums[i]) - 1; 
        if(nums[index] < 0) {
            repeating = abs(nums[i]);
            break;
        }else{
            nums[index] = -1 * nums[index];
        }
    }

    int sum = 0;
    for(int i=0; i<nums.size(); i++) sum += abs(nums[i]);

    int e_sum = (nums.size() * (nums.size() + 1)) / 2;
    missing = e_sum - (sum - repeating);

    return {repeating, missing};
}