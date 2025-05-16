// Leaders in an Array
// Problem Statement: Given an array, print all the elements which are leaders. 
// A Leader is an element that is greater than all of the elements on its right side in the array.

#include<iostream>
using namespace std;

// an element is leader if all the element in right side is greater
// Example 1:
// Input:
//  arr = [4, 7, 1, 0]
// Output:
//  7 1 0
// Explanation:
//  Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

vector<int> all_right_greater_element(vector<int> nums){
    vector<int> temp;
    int maxi_from_right = INT_MIN;
    for(int i=nums.size()-1; i>=0; i++){
        if(nums[i] > maxi_from_right){
            temp.push_back(nums[i]);
        }
        maxi_from_right = max(maxi_from_right, nums[i]);
    }
    return temp;
}

