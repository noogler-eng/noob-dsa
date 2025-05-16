// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. 
// Find the total number of subarrays having bitwise XOR of all elements equal to k.

#include<iostream>
using namespace std;

// Example 1:
// Input Format: A = [4, 2, 2, 6, 4] , k = 6
// [4, 6, 4, 2, 6] .... 
// now we can see that 
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]


// brute force 
// time complexity o(N*N)
// space complexity o(1)
int count_no_of_subarray(vector<int> nums, int k){
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        int x = 0;
        for(int j=i; j<nums.size(); j++){
            x = x ^ nums[j];
            if(x == k){
                count++;
            }
        }
    }
    return count;
}


// x ^ y = k
// make sure you start with ps = 0
// 0 ^ x = x (always)
// time complexity o(N)
// space complexity o(1)
int count_no_of_subarray(vector<int> nums, int k){
    unordered_map<int, int> m;
    int ps = 0;
    int count = 0;
    m[0]++;
    for(int i=0; i<nums.size(); i++){
        ps = ps ^ nums[i];
        if(m.find((ps ^ k)) != m.end()) count += m[(ps ^ k)];
        m[ps]++;
    }
    return count;
}