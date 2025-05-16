// Number Of Enclaves

// You are given an m x n binary matrix grid, where 0 
// represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) 
// land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot 
// walk off the boundary of the grid in any number of moves.

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j] = 0;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for(int n=0; n<4; n++){
            int new_x = i + dx[n];
            int new_y = j + dy[n];
            if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == 1){
                dfs(new_x, new_y, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && (grid[i][j] == 1)) dfs(i, j, grid);
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};