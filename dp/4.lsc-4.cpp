// Longest String Chain
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, 
// where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. 
// A single word is trivially a word chain with k == 1.

// time complexity o(N*N * word{length})
// space complexity o(N)
#include<iostream>
using namespace std;

class Solution {
public:
    bool isDiffOne(string word1, string word2){
        int i=0, j=0;
        if(word1.length() - word2.length() != 1) return false;
        while(i !=word1.length() && j != word2.length()){
            if(word1[i] == word2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(j == word2.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isDiffOne(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};