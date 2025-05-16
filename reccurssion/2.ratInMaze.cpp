// Rat In Maze

#include<iostream>
using namespace std;

void helper(vector<vector<int>> &places, int row, int col, int n, string &val, vector<string> &ans){
    if(row == n-1 && col == n-1) {
        ans.push_back(val);
        return;
    }
    
    // now rat can move all the 4 directions
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    // So Down and Right are the natural first choices.
    vector<char> dc = {'D', 'L', 'R', 'U'};

    int maxi = 0;
    for(int i=0; i<4; i++){
        int new_x = row + dx[i];
        int new_y = col + dy[i];
        

        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && places[new_x][new_y] == 1){
            places[new_x][new_y] = 0;
            val.push_back(dc[i]);
            helper(places, new_x, new_y, n, val, ans);
            val.pop_back();
            places[new_x][new_y] = 1;
        }
    }
    
}

vector < string > searchMaze(vector < vector < int >> & places, int n) {
    vector<string> ans;
    string val = "";
    if(places[0][0] == 0 || places[n-1][n-1] == 0) return ans;

    places[0][0] = 0;
    helper(places, 0, 0, n, val, ans);
    return ans;
}