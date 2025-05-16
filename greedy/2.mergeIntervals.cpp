// Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.


#include<iostream>
using namespace std;

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// 1 --- 3
//    2 ------- 6 (start < prev_end)
//                 8 ------- 10
//                                  15 ---- 18

// time complexity o(N)
// space complexity o(1) not including this ans vector of vector
vector<vector<int>> merge (vector<vector<int>> &intervals){
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