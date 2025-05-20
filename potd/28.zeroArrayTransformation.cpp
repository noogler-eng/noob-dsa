// Zero Array Transformation

// Time limit exceede
#include<iostream>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > queries.size()) return false;
        }
        
        
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            while(start <= end){
                if(nums[start] == 0) {
                    start++;
                    continue;
                }
                nums[start]--;
                start++;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) return false;
        }
        return true;
    }
};


// important approach -------------------
// optmised version
// this is nice approach (as a difference array)
// [4, 3, 2, 1], queries = [[1,3],[0,2]]
// [4, 3, 2, 1]
// [1, 1, 0, -1, -1]
// time compleity o(N)
// space complexity o(N)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size()+1, 0);
        // const auto& q = queries[i]
        for(const auto& q: queries){
            diff[q[0]]++;
            if(q[1] + 1 < nums.size())
                // here we are decreasing it as at completeion of subarray
                // we have to remove all the sum we can reduced
                diff[q[1]+1]--;
        }   

        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            cnt += diff[i];
            if(nums[i] > cnt) return false;
        }

        return true;
    }
};