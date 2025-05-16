// Longest Unequal Adjacent Groups Subsequence I
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

#include <iostream>
using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans0;
        vector<string> ans1;

        int j = 0, prev = 0;
        while(j < groups.size()){
            if(prev != groups[j]){
                ans0.push_back(words[j]);
                prev = groups[j];
            }
            j++;
        }

        prev = 1;
        j = 0;
        while(j < groups.size()){
            if(prev != groups[j]){
                ans1.push_back(words[j]);
                prev = groups[j];
            }
            j++;
        }

        return ans1.size() > ans0.size() ? ans1: ans0;
    }
};