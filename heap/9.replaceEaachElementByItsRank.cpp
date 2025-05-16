// Replace Elements By Its Rank In Array

// Input: 20 15 26 2 98 6
// Output: 4 3 5 1 6 2

#include<iostream>
using namespace std;

// time complexity O(NlogN)*2
// space complexity O(N)
vector<int> replaceWithRank(vector<int> &ele, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<ele.size(); i++) pq.push({ele[i], i});

    int count = 1;
    vector<int> ans(ele.size());
    while(!pq.empty()){
        int index = pq.top().second;
        int val = pq.top().first;
        pq.pop();
        ans[index] = count;
        
        // dont increase the rank if there are same element
        if(!pq.empty() && val != pq.top().first) count++;
    }

    return ans;
}