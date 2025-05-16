// Find Minimum Time To Reach Last Room 2
// There is a dungeon with n x m rooms arranged as a grid.
// You are given a 2D array moveTime of size n x m, where moveTime[i][j] 
// represents the minimum time in seconds when you can start moving to that room. 
// You start from the room (0, 0) at time t = 0 and can move to an adjacent room. 
// Moving between adjacent rooms takes one second for one move and two seconds for 
// the next, alternating between the two.

// Return the minimum time to reach the room (n - 1, m - 1).
// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

#include<iostream>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // gives me minimum time at the top
        priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
        vector<vector<int>> timeValues(n, vector<int>(m, INT_MAX));
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        pq.push({{0, 1},{0, 0}});
        timeValues[0][0] = 0;

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int time = pq.top().first.first;
            int add = pq.top().first.second;
            pq.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >=0 && new_x < n && new_y >=0 && new_y <m){
                    if(moveTime[new_x][new_y] <= time && timeValues[new_x][new_y] > time + add){
                        timeValues[new_x][new_y] = time + add;
                        pq.push({{time + add, (add == 1 ? 2: 1)}, {new_x, new_y}});
                    }else if(moveTime[new_x][new_y] > time && timeValues[new_x][new_y] > moveTime[new_x][new_y] + add){
                        timeValues[new_x][new_y] = moveTime[new_x][new_y] + add;
                        pq.push({{moveTime[new_x][new_y] + add, (add == 1 ? 2: 1)}, {new_x, new_y}});
                    }
                }
            }

        }
        return timeValues[n-1][m-1];
    }
};