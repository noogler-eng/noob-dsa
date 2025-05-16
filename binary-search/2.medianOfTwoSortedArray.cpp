// Median Of Two Sorted Array

#include<iostream>
using namespace std;

// time complexity o(N+M)*2
// space complexity o(1)
class Solution {
public:
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k){
        // code here
        int i=0, j=0;
        int count = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                count++;
                if(count == k) return nums1[i];
                i++;
            }else{
                count++;
                if(count == k) return nums2[j];
                j++;
            }
        }

        while(i < nums1.size()){
            count++;
            if(count == k) return nums1[i];
            i++;
        }

        while(j < nums2.size()){
            count++;
            if(count == k) return nums2[j];
            j++;
        }

        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // even
        if((n1 + n2) % 2 == 0) {
            int val = ((n1 + n2) / 2);
            int val1 = findKthElement(nums1, nums2, val);
            int val2 = findKthElement(nums1, nums2, val+1);
            return double(findKthElement(nums1, nums2, val) + findKthElement(nums1, nums2, val+1)) / 2.0;
        }else{
            int val = ((n1 + n2) / 2) + 1;
            return findKthElement(nums1, nums2, val);
        }
    }
};