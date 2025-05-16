// Kadane's Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
// Output: 6 

#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
int printLargestSumFromSubarray(vector<int> nums){
    int sum = 0, maxi = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxi = max(sum, maxi);
        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}