// K Most Freq Element
// Given an integer array nums and an integer k, 
// return the k most frequent elements. 
// You may return the answer in any order

#include<iostream>
using namespace std;

// time complexity o(NLogN) + o(N)
// space complexity o(N)*2 not including the ans space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // minimum freq elements are at the top
        for(auto i: m){
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> temp;
        while(!pq.empty()){
            temp.push_back(pq.top().second);
            pq.pop();
        }

        return temp;
    }
};