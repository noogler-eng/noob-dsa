// Longest Bitonic Subsequence

// A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:
// First, increase till a point and then decrease.
// Goes on increasing (Longest increasing subsequence)
// Goes on decreasing (Longest decreasing subsequence)

#include<iostream>
using namespace std;

// time complexity o(N*N)*2
// space complexity o(N)*2
int longestBiotonicSubseq(vector<int> nums){
    int n = nums.size();
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);

    // first finding the longest increasing subseq
    for(int i=0; i<n; i++){
        int curr = nums[i];
        int maxi = 0;
        for(int j=0; j<i; j++){
            if(curr > nums[j]) maxi = max(maxi, inc[j]);
        }
        inc[i] += maxi;
    }

    // finding the longest decreasing subseq
    for(int i=n-1; i>=0; i--){
        int curr = nums[i];
        int maxi = 0;
        for(int j=n-1; j>i; j--){
            if(curr > nums[j]) maxi = max(maxi, dec[j]);
        }
        dec[i] += maxi;
    }

    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, inc[i] + dec[i] - 1);
    }

    return maxi;
}

