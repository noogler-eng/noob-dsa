// Minimum Cost Of Ropes

#include<iostream>
using namespace std;

// Given an array, arr[] of rope lengths, connect all ropes into a 
// single rope with the minimum total cost. The cost to connect two 
// ropes is the sum of their lengths. 

// Input: arr[] = [4, 3, 2, 6]
// time complexity N(logN)
// space complexity O(N)
int minCost(vector<int>& arr) {
    // minimum priority queue
    // topmost -> minimum
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<arr.size(); i++) pq.push(arr[i]);
    
    int cost = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += (first + second);
        pq.push(first + second);
    }

    return cost;
}