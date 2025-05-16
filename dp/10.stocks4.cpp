// Buy and Sell Stock colldown period
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like 
// (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include<iostream>
using namespace std;

// time complexity o(N*2)
// space complexity o(N*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
        for(int i = n-1; i >=0; i--){
            for(int j=1; j>=0; j--){
                if(j == 1){
                    int sell = prices[i] + dp[i+2][0];
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