// Print Longest Increasing Subseq

#include<iostream>
using namespace std;

class Solution {
public:

    // Input: nums = [10,9,2,5,3,7,101,18]
    // [10, 9, 2, 5, 3, 7, 101, 18]
    // [0, 0, 0, 0, 0, 0, 0, 0]
    // [1, 1, 1, 2, 2, 3, 4, 4] max longest increasing subseq = 4
    // [] thi is hash vector for pathway (getting the path of longest subseq)
    // [0, 1, 2, 2, 2, 4, 5, 4]

    // time complexity o(N*N)
    // space complexity o(N)*2 not including ans one
    vector<int> printingLongestIncreasingSubsequence(vector<int>& nums) {
        vector<int> lis(nums.size(), 0);
        vector<int> hash(nums.size());
        for(int i=0; i<nums.size(); i++) hash[i] = i;
        int ind = -1;

        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i], maxi_internal = 0;
            int index_internal = -1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
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
