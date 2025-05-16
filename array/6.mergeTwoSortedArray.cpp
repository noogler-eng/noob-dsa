// Merge Two Sorted Array
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m 
// in non-decreasing order. Merge them in sorted order. 
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]

#include<iostream>
using namespace std;

// brute force approach
// time complexity o(N1) + o(N2) + o((N1+N2)log(N1 + N2)) 
// we can remove this NlogN by left and rght two pointers ....
// space complexity o(N1 + N2)
void mergerTwoSortedrrays(vector<int> &nums1, int n, vector<int> &nums2, int m){
    vector<int> temp;
    for(int i=0; i<n; i++){
        temp.push_back(nums1[i]);
    }

    for(int i=0; i<m; i++){
        temp.push_back(nums2[i]);
    }

    sort(temp.begin(), temp.end());
    int index = 0;
    for(int i=0; i<n; i++){
        nums1[i] = temp[index];
        index++;
    }

    for(int i=0; i<m; i++){
        nums2[i] = temp[index];
        index++;
    }
}

// merging two sorted array without an extra space
// time complexity NLogN + MlogM + o(N + M)
// space complexity o(1)
void mergerTwoSortedrrays(vector<int> &nums1, int n, vector<int> &nums2, int m){
    // nums1 is sorted
    // nums2 is sorted
    int last = n-1, start = 0;
    while(last >= 0 && start < m && nums1[last] > nums2[start]){
        swap(nums1[last], nums2[start]);
        last--;
        start++;
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}