
#include<iostream>
using namespace std;

// time complexity o(NLogN) + O(N*N)
// space complexity o(N)*2
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // first sorting then make sure
        // nums[i] % nums[j] then count on j for i
        sort(nums.begin(), nums.end());
        vector<int> lis(nums.size(), 0);
        vector<int> hash(nums.size());
        for(int i=0; i<nums.size(); i++) hash[i] = i;
        int ind = -1;

        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i], maxi_internal = 0;
            int index_internal = -1;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(maxi_internal < lis[j]){
                        index_internal = j;
                        maxi_internal = lis[j];
                    }
                }
            }
            lis[i] = 1 + maxi_internal;
            if(index_internal != -1) hash[i] = index_internal;
            if(lis[i] > maxi){
                maxi = lis[i];
                ind = i;
            }
        }

        int index = ind;
        vector<int> temp;
        while(index != hash[index]){
            temp.push_back(nums[index]);
            index = hash[index];
        }
        temp.push_back(nums[index]);

        reverse(temp.begin(), temp.end());
        return temp;
    }
};