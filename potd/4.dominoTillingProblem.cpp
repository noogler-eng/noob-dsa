// Domino Tilling Problem
// https://leetcode.com/problems/domino-and-tromino-tiling/?envType=daily-question&envId=2025-05-05

#include<iostream>
using namespace std;

// this is extremely wrong code or wrong logic
class Solution {
public:
    int mod = pow(10, 9) + 7; 
    int numTilings(int n) {
        long long board_size =  2 * n;
        int value_by_2 = (board_size / 2) % mod;
        int value_by_3 = board_size % 3 == 1 ? 0: (board_size / 3) % mod;
        return (value_by_2 + value_by_3) % mod;
    }
};


// it is question of dp
// dp[n] = dp[n - 1] + dp[n - 2] + 2 * (dp[n - 3] + dp[n - 4] + ... + dp[0])
// there are 3 possiblites as we can placed vertically (two block), horizontally (two block) or 
// and we can also place (three block)
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        // this is initlization ...
        dp[0] = 1;
        if (n >= 1) dp[1] = 1;
        if (n >= 2) dp[2] = 2;

        // we are checking from i = 3 to ..... n
        for (int i = 3; i <= n; ++i) {
            // here we are moving back and checking 
            // the permutation in the i
            // for the two space we have two option like 
            // - place horizontally, 
            dp[i] = (2 * dp[i - 1] % mod + dp[i - 3] % mod) % mod;
        }
        return dp[n];
    }
};
