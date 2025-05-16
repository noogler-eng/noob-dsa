// Check If Two Strings Are Anagram

#include<iostream>
using namespace std;

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// time complexity o(N+M)
// space complexity o(N)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++) m[s[i]]++;
        
        for(int i=0; i<t.length(); i++){
            if(m.find(t[i]) != m.end()){
                m[t[i]]--;
                if(m[t[i]] == 0) m.erase(t[i]);
            }else{
                return false;
            }
        }

        if(m.size() != 0) return false;
        return true;
    }
};