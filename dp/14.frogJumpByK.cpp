// Dynamic Programming: Frog Jump with k Distances (DP 4)

#include<iostream>
using namespace std;

class Solution {
  public:
    int helper(vector<int> &height, int ind, int k){
      if(ind == 0) return 0;
      int minSteps = INT_MAX;

      for(int j=1; j<=k; j++){
        if(ind - j >= 0){
          int val = helper(height, ind-k, k) + abs(height[ind] - height[ind-j]);
          minSteps = min(minSteps, val);
        }
      }

      return minSteps;
    }

    int minEnergy(int N, int k, vector<int> height) {
        return helper(height, N, k);
    }
};
