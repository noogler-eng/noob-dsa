// Non Overlapping Intervals

// Given an array of intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. 
// For example, [1, 2] and [2, 3] are non-overlapping.

#include<iostream>
using namespace std;

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// here we have to count the number of intervals overlaping
// 1 --- 2
//       2 ---- 3
//              3 ---- 4
// 1 -----------3  (removing this one as it makes all overlapping)
// always remove maxi one...


int count_overlapps(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    int end = intervals[0][1];
    int count = 0;

    for(int i=1; i<intervals.size(); i++){
        vector<int> new_interval = intervals[i];
        if(new_interval[0] < end){
            count++;
            // removing with larger end
            end = min(end, new_interval[1]);
        }else{  
            end = new_interval[1];
        }
    }

    return count;
}   