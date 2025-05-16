// find the smallest divisor given a threshold

#include<iostream>
using namespace std;

// time complexity o(Nlog(maxi)), where N is the size of nums and maxi is the maximum value in nums
// space complexity O(1)
class Solution {
public:
    int isPossible(vector<int> &nums, int threshold, int mid){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil(double(nums[i]) / double(mid));
            if(sum > threshold) return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN, ans = -1;
        for(int i=0; i<nums.size(); i++) maxi = max(maxi, nums[i]);

        int low = 1, high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums, threshold, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};