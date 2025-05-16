// Merge Overlapping Sub-intervals
// Problem Statement: Given an array of intervals, merge all the overlapping 
// intervals and return an array of non-overlapping intervals.

// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// in this type of question sort on the basis of the ending overlap

#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                // sort in ascending order as by second element
                return (a[0] < b[0]);
             });

        int startInterval = intervals[0][0];
        int endInterval = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> new_interval = intervals[i];
            if (new_interval[0] > endInterval) {
                ans.push_back({startInterval, endInterval});
                startInterval = new_interval[0];
                endInterval = new_interval[1];
                continue;
            }

            if (new_interval[0] <= endInterval && endInterval < new_interval[1]) {
                endInterval = new_interval[1];
            }
        }

        ans.push_back({startInterval, endInterval});
        return ans;
    }
};