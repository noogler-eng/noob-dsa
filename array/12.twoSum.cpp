// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. 
// Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. 
// Otherwise, we will return {-1, -1}.

#include<iostream>
using namespace std;

// variant 1
// time complexity o(N) + o(NLogN)
// space complexity o(1)
bool isTwoSumPossible(vector<int> nums, int target){
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size()-1;

    // do not consider here equals as this will take two same element
    while(low < high){
        int sum = nums[low] + nums[high];
        if(sum == target){
            return true;
        }
        else if(sum < target){
            low++;
        }else {
            high--;
        }
    }
    return false;
}


// now variant 2
// we have to require indexing so indexing using pair then sort
// time complexity o(NlogN)
// space complexity o(N) * 2
pair<int, int> twoSum(vector<int> nums, int target){
    vector<pair<int, int>> temp(nums.size());
    for(int i=0; i<nums.size(); i++){
        temp[i] = {nums[i], i};
    }

    sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    });

    int low = 0;
    int high = temp.size()-1;
    while(low < high){
        int sum = temp[low].first + temp[high].first;
        if(sum == target){
            return {temp[low].second, temp[high].second};
        }else if(sum < target){
            low++;
        }else {
            high--;
        }
    }
    return {-1, -1};
}