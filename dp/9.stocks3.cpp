// Best Time To Buy And Sell Stocks 2
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.



#include<iostream>
using namespace std;

// working but gives TLE ...
class Solution {
public:
    int helper(vector<int>& prices, int index, bool isHold, int k){
        if(index == prices.size()) return 0;

        int val = 0;
        if(isHold){
            // can sell
            int sell = prices[index] + helper(prices, index+1, !isHold, k);
            // not sell
            int not_sell = helper(prices, index+1, isHold, k);
            val = max(sell, not_sell);
        }else if(k > 0){
            // can buy
            int buy = -1 * (prices[index]) + helper(prices, index+1, !isHold, k-1);
            // not buy
            int not_buy = helper(prices, index+1, isHold, k);
            val = max(buy, not_buy);
        }
        return val;
    }

    int maxProfit(vector<int>& prices) {
        int k = 2;
        return helper(prices, 0, false, k);
    }
};


// tabulation method
// time complexity o(N*2*2)
// space compleity o(N*2*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i = prices.size()-1; i>=0; i--){
            for(int j=1; j >= 0; j--){
                for(int n=k; n>=0; n--){
                    if(j == 1){
                        int sell = prices[i] + dp[i+1][!j][n];
                        int not_sell = dp[i+1][j][n];
                        dp[i][j][n] = max(sell, not_sell);
                    }else if(n > 0){
                        int buy = (-1 * prices[i]) + dp[i+1][!j][n-1];
                        int not_buy = dp[i+1][j][n];
                        dp[i][j][n] = max(buy, not_buy);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};