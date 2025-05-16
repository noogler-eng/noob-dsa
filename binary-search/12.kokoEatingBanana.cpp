// Koko Eatings Bananas

#include<iostream>
using namespace std;

// Input: piles = [3,6,7,11], h = 8
// time complexity NlogN
// space complexity o(1)
class Solution {
public:
    // remeber to send long long as int overflows here ...
    long long check(vector<int> &piles, long long mid){
        long long time = 0;
        for(int i=0; i<piles.size(); i++){
            time += (long long)piles[i] / mid;
            time += (piles[i] % mid > 0 ? 1: 0);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i=0; i<piles.size(); i++) maxi = max(maxi, piles[i]);
        
        int low = 1;
        int high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};