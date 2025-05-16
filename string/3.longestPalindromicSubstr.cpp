// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
#include<iostream>
using namespace std;


// substring means continously so for each character we have to check in left and in right
// babad
// let suppose a then moving left and moving right
// time complexity o(N*N*N)
// space complexity o(N) 
class Solution {
public:
    // we have to make sure that its odd or even
    int isPlaindrome(string s, int i, int j){
        int start = i;
        int end = j;
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int maxi = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(isPlaindrome(s, i, j)){
                    if(maxi < j-i+1){
                        ans = s.substr(i, j-i+1);
                        maxi = j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};


// optmised it 
// time complexity o(N*N)
// space complexity o(N)
// checking for each character we are moving left and right .....
// babd
// this is important approach
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        for(int i=0; i<s.length(); i++){
            // odd length palindorme
            int l = i, r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }

            // even length
            l = i, r = i+1;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        s.substr(start, maxLen);
    }
};