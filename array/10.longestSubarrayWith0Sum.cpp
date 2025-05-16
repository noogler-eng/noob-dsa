// Length of the longest subarray with zero Sum

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result: 5
// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// array[] = {9, -3, 3, -1, 6, -5}
// ps = [0, 9, 6, 9, 8, 14, 9], placing index instead of the count in map

#include<iostream>
using namespace std;

// brute force approach
// making each and every subarray with any sum = 0 then record it
// time complexity o(N*N)
// space complexity o(1)


// optmised approach
// time complexity o(N)
// space complexity o(N)
int find_longest_subarray_sum_o(vector<int> nums){
    unordered_map<int, int> m;
    int ps = 0;
    // suppose it someone with 0 in futrue then we have to handle that case also
    m[ps] = -1;
    int maxi = 0;

    for(int i=0; i<nums.size(); i++){
        ps = ps + nums[i];
        if(m.find(ps) != m.end()) {
            maxi = max(maxi, i - m[ps]);
            // if there is new same ps then why we chage its index
            // as we need the longest subarray that'why 
            continue;
        }

        // if the current ps is not present in m already
        // then only we are updating it
        m[ps] = i;
    }

    return maxi;
}