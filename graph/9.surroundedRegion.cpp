// Surorrounded Regions
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells 
// if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 
// 'X's in-place within the original board. You do not need to return anything.

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// we are using dfs
// time complexity o(N*E)
// space complexity o(1), not including ans matrix
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board){
        board[i][j] = '.';
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for(int n=0; n<4; n++){
            int new_x = i + dx[n];
            int new_y = j + dy[n];
            if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size() && board[new_x][new_y] == 'O'){
                dfs(new_x, new_y, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j== 0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
                    cout<<i<<" "<<j<<endl;
                    dfs(i, j, board);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};