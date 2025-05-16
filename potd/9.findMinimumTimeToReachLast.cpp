// Find Mimimum Time To Reach Last Room 1

#include<iostream>
using namespace std;

// There is a dungeon with n x m rooms arranged as a grid.
// You are given a 2D array moveTime of size n x m, 
// where moveTime[i][j] represents the minimum time in seconds when you can 
// start moving to that room. You start from the room (0, 0) at time t = 0 and 
// can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
// Return the minimum time to reach the room (n - 1, m - 1).
// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

// time complexity o(N*N*log(N*M)) here log when there was priority queue
// space complexity o(N*m) + 2 O(4)
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // Input: moveTime = [[0,4],[4,4]]
        // here simple queue is works
        // but we in dijastras use priority queue
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> visitedTime(moveTime.size(), vector<int>(moveTime[0].size(), INT_MAX));
        visitedTime[0][0] = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        int mini = INT_MAX;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                int time = visitedTime[x][y];

                if(new_x >= 0 && new_x < moveTime.size() && new_y >= 0 && new_y < moveTime[0].size()){
                    if(time >= moveTime[new_x][new_y] && visitedTime[new_x][new_y] > time + 1){
                        visitedTime[new_x][new_y] = time + 1;
                        q.push({new_x, new_y});
                    }else if(time < moveTime[new_x][new_y] && visitedTime[new_x][new_y] > 1 + moveTime[new_x][new_y]){
                        visitedTime[new_x][new_y] = 1 + moveTime[new_x][new_y];
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return visitedTime[moveTime.size()-1][moveTime[0].size()-1];
    }
};