// Kth Element In Two Sorted Array
// Problem Statement: Given two sorted arrays of size m and n respectively, 
// you are tasked with finding the element that would be at the kth position 
// of the final sorted array.

#include<iostream>
using namespace std;

// brute force approach
// time complexity o(NlogN)
// space complexity o(1)
// merge sorting


// time complexity o(N+M)
// space complexity o(1)
int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
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