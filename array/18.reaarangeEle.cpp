// Rearrange Array Elements by Sign

// Problem Statement:
// There’s an array ‘A’ of size ‘N’ with an equal number of positive and 
// negative elements. Without altering the relative order of positive and 
// negative elements, you must return an array of alternately positive and negative values.

// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output: 1 -4 2 -5

#include<iostream>
using namespace std;

// time complexity o(N)*2
// space complexity o(N)*2
void make_alternate_arragment(vector<int> nums){
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] < 0){
            neg.push_back(nums[i]);
        }else {
            pos.push_back(nums[i]);
        }
    }

    int index1 = 0;
    int index2 = 1;
    for(int i=0; i<nums.size(); i++){
        if(i % 2 == 0){
            nums[i] = pos[index1];
            index1++;
        }else{
            nums[i] = neg[index2];
            index2++;
        }
    }
}