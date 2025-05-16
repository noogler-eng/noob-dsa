// Best Time To Buy And Sell Stocks

#include<iostream>
using namespace std;

// Input: prices = [7,1,5,3,6,4]

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            int curr = prices[i];
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};