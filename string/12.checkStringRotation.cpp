// Rotate String

// Given two strings s and goal, return true if and only if s can become 
// goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        for(int i=0; i<s.length(); i++){
            int rotateBy = i % s.length();
            int isRunFull = 0;
            for(int j=0; j<s.length(); j++){
                if(s[j] != goal[(j + rotateBy) % s.length()]) break;
                isRunFull++;
            }
            if(isRunFull == s.length()) return true; 
        }
        return false;
    }
};