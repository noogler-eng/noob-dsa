// Substring With Same First and Last Characters

#include <iostream>
#include <unordered_map>
using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution {
  public:
    // this is constatnt as r value is fixed to 2
    // o(2) always
    int find(int n, int r){
        int ans = 1;
        for(int i=1; i<=r; i++){
            ans = ans * (n-r+i);
            ans = ans / i;
        }
        return ans;
    }
    
    int countSubstring(string &s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++) m[s[i]]++;
        
        int count = 0;
        for(auto i: m){
            count += i.second;
            count += find(i.second, 2);
        }
        
        return count;
    }
};