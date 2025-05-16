// Kadane's Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

#include<iostream>
using namespace std;

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
// ps = [-2, -1, -4, 0, -1, 1, 2, -3, 1], how the prfix sum will work here
// Output: 6 

vector<int> print_max_subarray_sum(vector<int> nums){
    // first finding the max sum then finding out the subarray with sum is this
    int sum = 0, maxi = INT_MIN;
    int startIndex = 0, endIndex = 0, tempStart = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(maxi < sum){
            endIndex = i;
            startIndex = tempStart;
            maxi = sum;
        }
        if(sum < 0){
            tempStart = i+1;
            sum = 0;
        }
    }

    vector<int> ans;
    for(int i=startIndex; i<=endIndex; i++){
        ans.push_back(nums[i]);
    }

    return ans;
}