// Kth Largest Element In a Stream

#include<iostream>
using namespace std;

// time complexity O(N)
// space complexity o(N)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // for the oops always use this to get the class variables
        this->k = k;
        int i=0;
        while(i < nums.size()){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
            i++;
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};
