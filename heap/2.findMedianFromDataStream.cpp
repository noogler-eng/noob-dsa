// Find Median From Data Stream
#include<iostream>
using namespace std;

// For example, for arr = [2,3,4], the median is 3
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5
// brute force approach
class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {}
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    // time complexity o(NlogN) in each and every call of this
    double findMedian() {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n % 2 == 0){
            return double(nums[n/2] + nums[(n-1)/2]) / 2.0;
        }else{
            return double(nums[n/2]);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// optimised version
// time complexity overall o(LogN) * N
// space complexity o(N) * 2
// new concept or logic ----------- (median is always in sorted array)
// here we get the topmost element of left and mini of the right
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) {
            left.push(num);
        }else{
            right.push(num);
        }

        if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }else if(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() + right.size() == 0) return 0;
        if(left.size() + right.size() == 1) {
            if(left.size() == 0) return right.top();
            else return left.top();
        } 


        int top_left = left.top();
        int min_right = right.top();
        if((left.size() + right.size()) % 2 == 0){
            return double(top_left + min_right) / 2.0;
        }else {
            if(left.size() > right.size()) return left.top();
            else return double(right.top());
        }
    }
};