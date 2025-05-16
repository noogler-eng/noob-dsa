// Finding 3 Digit Even Numbers
// https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12
#include<iostream>
using namespace std;

// time complexity o(N*N) + o(MlogM)
// space complexity o(N + M + 3)
class Solution {
public:
    void helper(vector<int>& digits, unordered_map<int, int> &m, vector<int> &ans, int k, int &num){
        if(k == 0){
            if(num % 2 == 0) ans.push_back(num);
            return; 
        }

        for(auto i: m){
            int initial = num;
            if(i.second == 0) continue;
            if (k == 3 && i.first == 0) continue;
            
            num = num * 10 + i.first;
            m[i.first]--;
            helper(digits, m, ans, k-1, num);
            num = initial;
            m[i.first]++;
        }

    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<digits.size(); i++) m[digits[i]]++;
        
        int num = 0;
        helper(digits, m, ans, 3, num);
        sort(ans.begin(), ans.end());
        return ans;
    }
};