// Longest Increasing Subseq

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(N)
class Solution {
public:

    // Input: nums = [10,9,2,5,3,7,101,18]
    // [10, 9, 2, 5, 3, 7, 101, 18]
    // [0, 0, 0, 0, 0, 0, 0, 0]
    // [1, 1, 1, 2, 2, 3, 4, 4] max longest increasing subseq = 4
    // [] thi is hash vector for pathway (getting the path of longest subseq)
    // [0, 1, 2, 2, 2, 4, 5, 4]

    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 0);
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i], maxi_internal = 0;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    maxi_internal = max(maxi_internal, lis[j]);
                }
            }
            lis[i] = 1 + maxi_internal;
            maxi = max(maxi, lis[i]);
        }
        return maxi;
    }
};



// very good method ---
// time complexity o(N*logn(N))
// space complexity o(N)
class Solution {
public:

    // Input: nums = [10,9,2,5,3,7,101,18]
    // [10, 9, 2, 5, 3, 7, 101, 18]
    // temp = [10]
    // temp = [9]
    // temp = [2]
    // temp = [2, 5]
    // temp = [3, 5]
    // temp = [3, 5, 7]
    // temp = [3, 5, 7, 101]
    // temp = [3, 5, 7, 18]   size = 4

    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(temp.empty() || nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }else{
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};