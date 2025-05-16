// Total Character in String After Tranformation 1
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-05-13
#include<iostream>
using namespace std;

// here time complexity is increasing due the making changes, so not making any changes
// time complexity O(N*T)
// space complexity o(!)
class Solution {
public:
    int mod = 1000000000 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        for(int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
        }

        int count = s.length();
        for(int i=0; i<t; i++){
            int noOfZ = freq[25];
            for(int j=25; j>0; j--){
                freq[j] = freq[j-1];
            }
            freq[0] = noOfZ;
            freq[1] += noOfZ;
            count = (count + noOfZ) % mod;
        }
        return count % mod;
    }
};