// Sort an array of 0s, 1s and 2s
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
// Write a program to in-place sort the array without using inbuilt sort functions. 
// ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include<iostream>
using namespace std;

// brute force approach
// time complexity o(NLogN)
// space complexity o(1)
void sort_the_array(vector<int> nums){
    sort(nums.begin(), nums.end());
}



// optmised version
// time complexity o(N)
// space complexity o(1)
void sort_the_array(vector<int> nums){
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;
    
    while(mid < high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    return;
}