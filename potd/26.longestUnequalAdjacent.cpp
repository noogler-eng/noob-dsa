// Longest Unequal Adjacent Groupd Subsequence 2

#include<iostream>
using namespace std;

// dp is being used to store the length of the longest subsequence
// as there is choices of select or not select

// time complexity of the code is O(n^2)
// space complexity of the code is O(n)
class Solution {
public:
    bool hammingDist(string a, string b){
        int i=0;
        int count = 0;
        while(i < a.length()){
            if(a[i] != b[i]) {
                count++;
                if(count > 1) return false;
            }
            i++;
        }

        if(count == 1) return true;
        return false;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n+1, 1);
        vector<int> path(n+1, -1);
        int maxi = 0;
        int startIndex = -1;

        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<words.size(); j++){
                if(words[i].length() == words[j].length() && groups[i] != groups[j] && hammingDist(words[i], words[j])) {
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
                startIndex = i;
            }
        }

        vector<string> final_ans;
        int i = startIndex;
        while(i != -1){
            final_ans.push_back(words[i]);
            i = path[i];
        }

        return final_ans;
    }
};