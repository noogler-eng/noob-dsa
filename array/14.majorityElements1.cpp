// Find the Majority Element that occurs more than N/2 times

// Problem Statement: Given an array of N integers, write a program to return an element 
// that occurs more than N/2 times in the given array. You may consider that such an 
// element always exists in the array.

#include<iostream>
using namespace std;

int find_majority_element(vector<int> nums){
    int ele = -1;
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        if(count == 0){
            ele = nums[i];
            count++;
        }else if(ele == nums[i]){
            count++;
        }else if(ele != nums[i]){
            count--;
        }
    }

    count = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == ele) count++;
    }

    if(count > nums.size() / 2) return ele;
    else return -1;
}