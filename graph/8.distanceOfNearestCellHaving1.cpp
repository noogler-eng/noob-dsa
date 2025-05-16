// Distance Of Nearest Cell Having 1
// Problem Statement: Given a binary grid of N*M. Find the distance of 
// the nearest 1 in the grid for each cell.

#include<iostream>
using namespace std;

// we will movie as we are seeing from the perspective of 0
// as we have to dinf the nearest distance of 0 from 1

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                    matrix[new_x][new_y] == 1) {
                    if (ans[new_x][new_y] > dist + 1) {
                        ans[new_x][new_y] = dist + 1;
                        q.push({{new_x, new_y}, dist + 1});
                    }
                }
            }
        }

        return ans;
    }
};