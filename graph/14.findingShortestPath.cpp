// Finding Shortest Path

#include<iostream>
using namespace std;

// 0/1 BFS algorithm's
// here we are working with 1 and 0 distnace 
// as when there is 0 distance then moving to the front
// when there is 1 or n then moving to the back

// vector<pair<int, int>> adj[] here it contains the adjacent points with the distance
// prioritizing the distances which has lower distance like with 0
int findingTheShortestPath(vector<pair<int, int>> adj[], int n, int src){
    deque<pair<int, int>> dq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    dq.push_back({src, 0});
    while(!dq.empty()){
        int node = dq.front().first;
        int curr_dist = dq.front().second;
        dq.pop_front();

        for(auto i: adj[node]){
            int neighbour = i.first;
            int new_dist = curr_dist + i.second;
            if(new_dist < dist[i.first]){
                dist[i.first] = new_dist;
                if(i.second == 1){
                    dq.push_back({i.first, new_dist});
                }else{
                    dq.push_front({i.first, new_dist});
                }
            }
        }
    }
    return dist[n-1];
}