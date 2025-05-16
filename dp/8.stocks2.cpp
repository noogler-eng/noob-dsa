// Best Time To Buy And Sell Stocks 2

#include<iostream>
using namespace std;

// time complexity o(2^N*2)
// space complexity o(N*2)
class Solution {
public:
    int helper(vector<int>& prices, int index, bool isHold, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;
        if(dp[index][isHold] != 0) return dp[index][isHold]; 

        int val = 0;
        if(isHold){
            // can sell
            int sell = prices[index] + helper(prices, index+1, !isHold, dp);
            // not sell
            int not_sell = helper(prices, index+1, isHold, dp);

            val = max(sell, not_sell);
        }else{
            // can buy
            int buy = -1 * (prices[index]) + helper(prices, index+1, !isHold, dp);
            // not buy
            int not_buy = helper(prices, index+1, isHold, dp);

            val = max(buy, not_buy);
        }
        return dp[index][isHold] = val;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        return helper(prices, 0, false, dp);
    }
};


// converion into tabulation method
// time complexity o(N)*2
// space complexity o(N)*2
// optmised version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for(int i = n-1; i >=0; i--){
            for(int j=1; j>=0; j--){
                if(j == 1){
                    int sell = prices[i] + dp[i+1][0];
                    int not_sell =  dp[i+1][1];
                    dp[i][j] = max(sell, not_sell);
                }else{
                    int buy = -1 * prices[i] + dp[i+1][1];
                    int not_buy = dp[i+1][0];
                    dp[i][j] = max(buy, not_buy);
                }
            }
        }
        return dp[0][0];
    }
};