// dijastra's algorithm
// used to find the minimum time, distance to reach certain place
#include<iostream>
using namespace std;

// Shortest Path With Multiple Weight
// here we will use the priority queue

// time complexity VlogE
// here logE is for inserting into the queue
vector<int> shortestPath(vector<pair<int, int>> adj[], int src, int n){
    vector<int> dist(n, INT_MAX);
    // we need mini above
    // always first taking the minimum distance nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int node = pq.top().second;
        int distt = pq.top().first;
        pq.pop();

        for(auto i: adj[node]){
            int new_dist = distt + i.second;
            if(new_dist < dist[i.first]){
                dist[i.first] = new_dist;
                pq.push({new_dist, i.first});
            }
        }
    }

    return dist;
}


// we can't find the shortest distance in the negative cycle
// as negative alswas makes the distance smaller in another round
// so for negative cycles dijastr'a will not work

// this is how we can print the path in the dijastra's algorithm
// in order to print the path we have to take care of the nodes to nodes
// like array of from nodes ....
vector<int> shortestPath(vector<pair<int, int>> adj[], int src, int n, int des){
    vector<int> dist(n, INT_MAX);
    vector<int> from(n, -1);
    // we need mini above
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int node = pq.top().second;
        int distt = pq.top().first;
        pq.pop();

        for(auto i: adj[node]){
            int new_dist = distt + i.second;
            // this is when we have to update the distance
            if(new_dist < dist[i.first]){
                dist[i.first] = new_dist;
                // we are comming from node
                // so now we can start from src and move until we can't get src
                from[i.first] = node;
                pq.push({new_dist, i.first});
            }
        }

        // printing the path
        int i=des;
        cout<<i<<" ";
        while(i != src && i >= 0){
            cout<<from[i]<<" ";
            i = from[i];
        }
    }

    return dist;
}