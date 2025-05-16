// K-th Largest Sum Contiguous Subarray
// Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. 
// In other words, identify the K-th largest sum from all possible subarrays and return it.

// Input: arr[] = [3, 2, 1], k = 2 
// arr[] = [3, 2, 1], k = 2
// arr[] = [3, 5, 6]

// Input: arr[] = [2, 6, 4, 1], k = 3
// arr[] = [2, 6, 4, 1], k = 3
// arr[] = [2, 8, 12, 13]

#include<iostream>
using namespace std;

// this is brute firce 
// time complexity o(N*N) + o(M) + o(N^2)log(N^2)
// space complexity o(N)
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> ans;

        for(int i=0; i<arr.size(); i++){
            int sum = 0;
            for(int j=i; j<arr.size(); j++){
                sum += arr[j];
                ans.push_back(sum);
            }
        }

        int kthLargest = -1;
        sort(ans.begin(), ans.end(), greater<>());
        return ans[k-1];
    }
};



// time complexity O(N*N*log(N))
// space complexity o(N)
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<arr.size(); i++){
            int sum = 0;
            for(int j=i; j<arr.size(); j++){
                sum += arr[j];
                if(pq.size() < k) pq.push(sum);
                else if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.top();
    }
};
