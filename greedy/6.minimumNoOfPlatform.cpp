// Minimum No Of Platform Required For Railway

// Problem Statement: We are given two arrays that represent the arrival 
// and departure times of trains that stop at the platform. 
// We need to find the minimum number of platforms needed at the railway station 
// so that no train has to wait.

#include<iostream>
using namespace std;

// Input: N=6, 
// arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
// dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

// 9 --- 9.2
//             9.45 --------------------- 12.0
//                  9.5 ------ 11.30
//                       11 ---------11.50
//                                                 18 ----- 20.0
// here minimum no of 3 platform required
// time complexity o(N) + 2*NlogN
// space complexity o(1)
int minimum_no_of_platform_required(vector<int> &arr, vector<int> &dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int n = arr.size(), count = 0, maxi = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            count++;
            i++;
        }else{
            count--;
            j++;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}