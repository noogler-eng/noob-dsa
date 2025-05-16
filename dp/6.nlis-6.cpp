// Number Of Longest Increasing Subseq
// Input: nums = [1,3,5,4,7]

#include<iostream>
using namespace std;

// [1, 3, 5, 4, 7]
// [1, 1, 1, 1, 1]
// [1, 2, 3, 3, 4]
// [1, 1, 1, 1, 1]
// [1, 1, 1, ]

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxLen = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }else if(dp[i] == 1 + dp[j]){
                        // already happens, if it again happens then increasing the count
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        // counting the maxLength counts
        int ans = 0;
        for(int i=0; i<n; i++){
            if(maxLen == dp[i]){
                ans+=count[i];
            }
        } 

        return ans;
    }
};