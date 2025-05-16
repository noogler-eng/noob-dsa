// Majority Elements 2

// Majority Elements(&gt;N/3 times) | 
// Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more 
// than N/3 times in the array. If no such element exists, return an empty vector.

// Input Format: N = 5, array[] = {1,2,2,3,2}
// Result: 2
// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1, ele2 = -1;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && (nums[i] != ele2 || count2 == 0)) {
                ele1 = nums[i];
                count1++;
            } else if (count2 == 0 && (nums[i] != ele1 || count1 == 0)) {
                ele2 = nums[i];
                count2++;
            } else if (nums[i] == ele1) {
                count1++;
            } else if (nums[i] == ele2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // now we are checking wheather this are correct or not
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ele1) count++;
        }

        if (count > nums.size() / 3) {
            ans.push_back(ele1);
        }

        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ele2) count++;
        }

        if (count > nums.size() / 3 && ele1 != ele2) {
            ans.push_back(ele2);
        }

        return ans;
    }
};