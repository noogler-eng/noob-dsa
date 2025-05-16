// Floor and Ceil in Sorted Array

// problem Statement: You're given an sorted array arr of n integers and an integer x. 
// Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include<iostream>
using namespace std;

// time complexity o(LogN)*2
// space complexity o(1)
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int floor = -1;
    int ceil = -1;
    
    int low = 0;
    int high = a.size()-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] <= x){
            floor = a[mid];
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    low = 0;
    high = a.size()-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] >= x){
            ceil = a[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return {floor, ceil};
}