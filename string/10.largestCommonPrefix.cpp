// Largest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include<iostream>
using namespace std;

// time complexity o(N*M)
// n is total size of vector
// m is the average size of string
// space complexity o(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for(int i=1; i<strs.size(); i++){
            int left = 0, right = 0;
            while(left < common.length() && right < strs[i].length()){
                if(common[left] != strs[i][right]) {
                    common = strs[i].substr(0, right);
                    break;
                }
                left++;
                right++;
            }

            if(left >= common.length() ||  right >= strs[i].length()){
                if(common.length() >= strs[i].length()){
                    common = strs[i];
                }
            }
        }
        return common;
    }
};