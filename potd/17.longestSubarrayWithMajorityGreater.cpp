// Longest Subarray with Majority Greater than K
// Given an array arr[] and an integer k, the task is to find the
// length of longest subarray in which the count of elements greater
// than k is more than the count of elements less than or equal to k.

// Input: arr[] = [1, 2, 3, 4, 1], k = 2
// ps = [0, -1, -2, -1, 0, -1]

#include <iostream>
using namespace std;

// this is not working ....
// time complexity o(N)
// space complexity o(1)
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k){
    int i = 0, j = 0, countG = 0, countL = 0, maxi = 0;
    while (j < arr.size()){
        if (arr[j] > k) countG++;
        else countL++;

        while ((i <= j) && countG <= countL){
            if (arr[i] > k) countG--;
            else countL--;
            i++;
        }

        if (countG > countL) maxi = max(j - i + 1, maxi);
        j++;
    }

    return maxi;
    }
};


// important question --------
// 1, 2, 3, 4, 1
// -1, -2,  
// time complexuty O(N)
// space complexity O(1)
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k){
        int sum = 0, maxi = 0;
        unordered_map<int, int> m;

        m[0] = -1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > k) sum += 1;
            else sum -= 1;
            // here what are we doing, checking if sum is greater to 0 or not
            // if sum is greater to 0 then surely it is majority > k
            if(sum > 0) maxi = max(maxi, i+1);
            if(m.find(sum - 1) != m.end()) maxi = max(maxi, i - m[sum - 1]);

            // stroing if not found .....
            // if already there then not store it as we need longest 
            if(m.find(sum) == m.end()) m[sum] = i;
        }
        return maxi;
    }
};
