// Minimum Swaps To Sort
// https://leetcode.com/contest/weekly-contest-450/problems/minimum-swaps-to-sort-by-digit-sum/?slug=smallest-index-with-digit-sum-equal-to-index&region=global_v2

#include<iostream>
using namespace std;

// important question
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // storing the digit sum, number, index for sorting
        vector<pair<int, pair<int, int>>> digits_sum(nums.size(), {0, {0, 0}});
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            while(temp > 0){
                digits_sum[i].first += temp % 10;
                temp = temp / 10;
            }
            digits_sum[i].second.first = nums[i];
            digits_sum[i].second.second = i;
        }       

        // this is a classic problem ---------------------------
        // sort it
        sort(digits_sum.begin(), digits_sum.end());
        
        // mapping the index of number to the after sorted index
        vector<int> m(nums.size());
        for(int i=0; i<nums.size(); i++) m[i] = digits_sum[i].second.second;
        vector<bool> isVisited(nums.size(), false);


        int swaps = 0;
        // time complexity o(N)
        for(int i=0; i<nums.size(); i++){
            // means simmillar place
            if(isVisited[i] || m[i] == i) continue;
            
            int cycle_size = 0;
            int j = i;
            while(!isVisited[j]){
                isVisited[j] = true;
                // number compones from m[j]th index
                // one swapping is there
                j = m[j];
                ++cycle_size;
            }

            // adinng the swapping cycle into swaps ...
            if(cycle_size > 0){
                swaps += cycle_size - 1;
            }
        }

        return swaps;
    }
};