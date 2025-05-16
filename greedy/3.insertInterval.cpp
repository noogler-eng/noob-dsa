// Insert Interval
// https://leetcode.com/problems/insert-interval/description/

#include<iostream>
using namespace std;

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// 1 ---- 3
//              6 ----- 9
//    2 -----5 (inserting it into this one)


// here the merge intervals and insert intervals almost same question
// only you have to push the inserting vector into intervals vector before same code
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            vector<int> new_interval = intervals[i];
            if(new_interval[0] <= end){
                end = max(end, new_interval[1]);
            }else{
                ans.push_back({start, end});
                start = new_interval[0];
                end = new_interval[1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};
