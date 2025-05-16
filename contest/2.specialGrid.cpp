// Special Grid
// https://leetcode.com/contest/weekly-contest-448/problems/fill-a-special-grid/?slug=merge-operations-for-minimum-travel-time&region=global_v2
// Time complexiyt o(N*N)
// space complexity o(N*N)
class Solution {
public:
    void fillGrid(vector<vector<int>>& grid, int row, int col, int size, int start) {
        if (size == 1) {
            grid[row][col] = start;
            return;
        }

        int halfSize = size / 2;
        int count = size * size;
        int quarterCount = count / 4;

        fillGrid(grid, row, col + halfSize, halfSize, start);
        fillGrid(grid, row + halfSize, col + halfSize, halfSize, start + quarterCount);
        fillGrid(grid, row + halfSize, col, halfSize, start + 2 * quarterCount);
        fillGrid(grid, row, col, halfSize, start + 3 * quarterCount);
    }
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N; 
        vector<vector<int>> grid(size, vector<int>(size, 0));

        fillGrid(grid, 0, 0, size, 0);

        return grid;
    }
};©leetcode