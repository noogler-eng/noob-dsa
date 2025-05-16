// Largest Number In K Swap
// Backtracking ...

#include<iostream>
#include<string>
using namespace std;

// here we are checking the max and comparing string works
// string comparsion works
// "54321" > "12345"     // true
// "987654" < "998877"   // true
// "10000" > "9999"      // true
class Solution {
  public:
    void findBig(string &s, string &num){
        if(s > num) num = s;
    }
  
    void helper(string &s, int k, int i, string &num){
        if(k == 0 || i == s.length()) {
            findBig(s, num);
            return;
        }

        int maxChar = s[i];
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] > maxChar)
                maxChar = s[j];
        }

        if (maxChar == s[i]) {
            helper(s, k, i + 1, num);
            return;
        }

        
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] == maxChar) {
                swap(s[i], s[j]);
                helper(s, k - 1, i + 1, num);
                swap(s[i], s[j]);
            }
        }
    }

  
    string findMaximumNum(string& s, int k) {
        string num = s;
        helper(s, k, 0, num);
        return num;
    }
};