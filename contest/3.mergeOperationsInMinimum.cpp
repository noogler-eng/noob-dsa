// Merge Operations In Minimum Time Travel
// https://leetcode.com/contest/weekly-contest-448/problems/merge-operations-for-minimum-travel-time/?slug=fill-a-special-grid&region=global_v2

// Each time[i] represents the time (in minutes) required to travel 1 km between position[i] and position[i + 1]
// Input: l = 10, n = 4, k = 1, position = [0,3,8,10], time = [5,8,3,6]
// Input: l = 5, n = 5, k = 1, position = [0,1,2,3,5], time = [8,3,9,3,3]


// [0, 3, 8, 10]
// [5, 8, 3, 6] // merged maximum time one
// 3 * 5 + (5 * 8) + (2 * 3) = 61

// [0,1,2,3,5]
// [8,3,9,3,3]  // merger max one

// no this is not working
class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> costs(0, n);

        for(int i=1; i<n; i++){
            int cost = (position[i] - position[i-1]) * time[i-1];
            costs[i] = cost;
        }

        sort(cost.begin(), cost.end(), greater<int>());
        for(int i=0; i<k; i++) cost[i] = 0;
        
        int total = 0;
        for (int c : costs) total += c;
        
        return total;
    }
};