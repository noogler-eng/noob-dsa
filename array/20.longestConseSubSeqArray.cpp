// Longest Consecutive Sequence in an Array
// nice intutuion question

// Problem Statement: You are given an array of ‘N’ integers. You need to find the 
// length of the longest sequence which contains the consecutive elements.

// Input: [100, 200, 1, 3, 2, 4]
// Output: 4

#include<iostream>
using namespace std;

// brute force appraoch
// we can't sort here as we have to movie in single direction only
// we need to maintain order here
int longest_consecutive_subseq(vector<int> nums){
    sort(nums.begin(), nums.end());

    int maxi = 0;
    int count = 0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]+1 == nums[i+1]){
            count++;
            maxi = max(maxi, count);
        }else{
            count = 0;
        }
    }

    return maxi + 1;
}