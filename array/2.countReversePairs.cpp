// Count Reverse Pairs
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. 
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Input: N = 5, array[] = {1,3,2,3,1)

#include<iostream>
using namespace std;

// brute force approach
// time complexity o(N*N)
// space complexity o(1)
int no_of_count_reverse_pairs(vector<int> nums){
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] > 2 * nums[j]) count++;
        }
    }
    return count;
}


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
                if ((long long)num > 2LL * nums[right])
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