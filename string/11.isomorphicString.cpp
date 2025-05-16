// Isomorphic String

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving 
// the order of characters. No two characters may map to the same character, but a character may map to itself.

// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.

#include<iostream>
using namespace std;

// we have to preser the order also
// time complexity o(N)
// space complexity o(N) * 2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char ,int> m;
        unordered_map<char, bool> isMapped;

        for(int i=0; i<s.length(); i++){
            if(m.find(s[i]) != m.end()){
                if(t[i] != m[s[i]]) return false;
                else continue;
            }else{
                if(isMapped[t[i]]) return false;
                m[s[i]] = t[i];
                isMapped[t[i]] = true;
            }
        }
        return true;
    }
};
