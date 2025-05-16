// Count The Subarray With Given Sum

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include<iostream>
using namespace std;

// Input: nums = [1,2,3], k = 3
// ps = [0, 1, 3, 6]
// 

int count_subarray_with_given_sum(vector<int> nums, int k){
    int ps = 0;
    unordered_map<int, int> m;
    m[ps] = 1;

    int count = 0;
    for(int i=0; i<nums.size(); i++){
        ps+=nums[i];
        if(m.find(ps - k) != m.end()) count += m[ps-k];
        m[ps]++;
    }
    return count;
}