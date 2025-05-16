// Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11

#include<iostream>
using namespace std;

// Given an integer array arr, return true if there are three consecutive 
// odd numbers in the array. Otherwise, return false.
//  arr = [2,6,4,1]

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] % 2 != 0) {
                count++;
                if(count == 3) return true;
            } else count = 0;
        }
        return false;
    }
};