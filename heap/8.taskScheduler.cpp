// Task Scheduler

// Input: tasks = ["A","A","A","B","B","B"], n = 2

#include<iostream>
using namespace std;

// You are given an array of CPU tasks, each labeled with a letter from A to Z, 
// and a number n. Each CPU interval can be idle or allow the completion of one 
// task. Tasks can be completed in any order, but there's a constraint: there has 
// to be a gap of at least n intervals between two tasks with the same label.

// Input: tasks = ["A","C","A","B","D","B"], n = 1
// A -> 2   1    0
// B -> 2   1    0
// c -> 1               0
// D -> 1               0

// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// A -> 3   2 
// B -> 3   2     1 + max(n - (m.size() - 1))

// important question ---- 
// we have used greedy appraoch
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> m;

        for(int i=0; i<tasks.size(); i++) m[tasks[i]]++;
        for(auto i: m) pq.push({i.second, i.first});
        
        int top_fre = pq.top().first - 1;
        int no_of_slots = top_fre * n;
        pq.pop();

        // i have to find the nil number of slots
        while(!pq.empty()){
            no_of_slots = no_of_slots - min(pq.top().first, top_fre);
            pq.pop();
        }

        return tasks.size() + max(0, no_of_slots);
    }
};

// AAAABBBCCCDDD
// ABCABCABCAD.AD..D