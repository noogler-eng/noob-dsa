// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j 
// then you have to find pair (A[i],A[j]) such that A[j] < A[i].

#include<iostream>
using namespace std;

// more optmised version
// merger sorting technique
// time complexotty o(NlogN) * 2 as both sorting and count inversion runs parallely
// space complexity o(M)
class Solution {
public:
    void sort(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        int index = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[index];
            index++;
        }
    }

    int countInversions(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid+1;
        while (low <= mid) {
            long long num = nums[low];
            while (right <= high) {
                // here the right part is sorted
                if ((long long)num > nums[right])
                    right++;
                else
                    break;
            }
            count += (right - (mid + 1));
            low++;
        }
        return count;
    }

    int merge(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        cnt += merge(nums, low, mid);
        cnt += merge(nums, mid + 1, high);
        cnt += countInversions(nums, low, mid, high);
        sort(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};