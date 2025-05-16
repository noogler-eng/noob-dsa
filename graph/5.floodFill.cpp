// Flood Fill
// You are given an image represented by an m x n grid of integers image, 
// where image[i][j] represents the pixel value of the image. You are also 
// given three integers sr, sc, and color. Your task is to perform a flood 
// fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent 
// (pixels that share a side with the original pixel, either horizontally or vertically) 
// and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels 
// and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
//Return the modified image after performing the flood fill.

#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(N) + 2 * o(4)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int sartingColor = image[sr][sc];
        if(sartingColor == color) return image;
        int n = image.size();
        int m = image[0].size();

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        q.push({sr, sc});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            image[x][y] = color;
            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && image[new_x][new_y] == sartingColor){
                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};