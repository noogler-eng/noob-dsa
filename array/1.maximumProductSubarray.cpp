// Maximum Product Subarray in an Array
// Problem Statement: Given an array that contains both negative and positive integers, 
// find the maximum product subarray.

//  Nums = [1,2,3,4,5,0]
//  Nums = [1,2,-3,0,-4,-5]
// [1, 2, -6, 1, -4, 20]
// [-6 ,-6 ,-3 ,1 ,20 ,-5]

#include<iostream>
using namespace std;

// time complexity o(N) * 2
// space complexity o(1)
int maximum_product_subarray(vector<int> nums){
    int maxi = INT_MIN;
    int from_right = 1;
    int from_left = 1;
    for(int i=0; i<nums.size(); i++){
        from_left = from_left * nums[i];
        maxi = max(maxi, from_left);
        if(from_left == 0) from_left = 1;
    }

    for(int j=nums.size()-1; j>=0; j--){
        from_right = from_right * nums[j];
        maxi = max(maxi, from_right);
        if(from_right == 0) from_right = 1;
    }

    return maxi;
}
