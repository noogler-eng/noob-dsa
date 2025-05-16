// Minimum Equal Sum Of Two Arrays After Replacing Zeroes
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10

#include<iostream>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long count1 = 0, count2 = 0, sum1 = 0, sum2 = 0;
        
        for(int i = 0; i<nums1.size(); i++) {
            if(nums1[i] == 0) count1++;
            sum1 += nums1[i];
        }
        
        for(int i = 0; i<nums2.size(); i++) {
            if(nums2[i] == 0) count2++;
            sum2 += nums2[i];
        }

        cout<<sum1<<" "<<sum2<<endl;
        if(sum1 == sum2) {
            if(count1 == count2) return sum1 + count1;
            else{
                if(count1 == 0 || count2 == 0) return -1;
                else if(count1 > count2){
                    return sum1 + count1;
                }else if(count2 > count1){
                    return sum2 + count2;
                }
            }
        }

        if(sum1 > sum2){
            if(count2 == 0 || ((count2 > sum1 - sum2) && count1 == 0)) return -1;
            return max(sum1 + count1, sum2 + count2);
        }else{
            if(count1 == 0 || ((count1 > sum2 - sum1) && count2 == 0)) return -1;
            return max(sum1 + count1, sum2 + count2);
        }
    }
};