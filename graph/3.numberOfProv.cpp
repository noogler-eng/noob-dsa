// Number Of Provinces

// There are n cities. Some of them are connected, 
// while some are not. If city a is connected directly 
// with city b, and city b is connected directly with city 
// c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 
// if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N) + o(N)
class Solution {
public:
    void dfs(int node, vector<bool> &isVis, vector<vector<int>> arr){
        isVis[node] = true;

        for(auto i: arr[node]){
            if(!isVis[i]){
                dfs(i, isVis, arr);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // making an adjacent vector
        vector<vector<int>> arr(isConnected.size());
        vector<bool> isVis(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!isVis[i]){
                count++;
                dfs(i, isVis, arr);
            }
        }
        return count;
    }
};