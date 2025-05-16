// Rotten Oranges

// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent 
// to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
// If this is impossible, return -1.

#include<iostream>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        
        int noOfFresh = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1) noOfFresh++;
                else if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        int maxiCount = 0;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    noOfFresh--;
                    q.push({{newX, newY}, steps+1});
                    maxiCount = max(maxiCount, steps+1);
                }
            }
        }

        return noOfFresh == 0 ? maxiCount: -1;
    }
};