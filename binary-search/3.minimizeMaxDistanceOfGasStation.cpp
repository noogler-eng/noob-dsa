// Minimize Max Distance Between any Two Gas Station
// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, 
// which contains positive integer positions of ‘n’ gas stations on the 
// X-axis. You are also given an integer ‘k’. You have to place 'k'
// new gas stations on the X-axis. You can place them anywhere on the 
// non-negative side of the X-axis, even on non-integer positions. 
// Let 'dist' be the maximum value of the distance between adjacent 
// gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the a
// ctual answer is 0.65421678124, it is okay to return 0.654216.
// Our answer will be accepted if that is the same as the actual answer up to 
// the 6th decimal place.

#include<iostream>
using namespace std;

// stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// k = 9

// now we have to place the k gas station in between of this stations
// here this is easy case as we placed each in between of them


// stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
// k = 2 then 
// [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
// max = [3, 6, 7, 14, 11, 23, 5, 17, 6]
// now the max two distance will be
// 23 so place there 
// [3, 6, 12, 19, 33, 44, * , 67, 72, 89, 95] 
// [3, 6, 12, 19, 33, 44, * , 67, 72, *, 89, 95] 
// this is how the gas station will be placed

// so brute force requires at leat o(N*N)
// space o(N)

// this is wrong approach 
// we have to return afterward the maximized distance (after placing k stations)
// time complexity o(N + k)
// space complexity o(N)
double findSmallestMaxDist(vector<int> &stations, int k) {
    // max heap which will give me max value at the top
    priority_queue<double> pq;

    for(int i=1; i<stations.size(); i++){
        pq.push(stations[i] - stations[i-1]);
    }

    while(k > 0 && !pq.empty()){
        double val = pq.top();
        pq.pop();
        pq.push((val - 1) / 2);
        pq.push((val - 1) / 2);
        k--;
    }

    return pq.top();
}
// reason 
stations = [0, 10]
// k = 2  // We can add 2 stations
// Initial gap: 10

// You push 10 into the max-heap:

// pq = [10]
// Now you simulate k = 2 splits:

// Pop 10, split → 5, 5 → pq = [5, 5]
// Pop 5, split → 2.5, 2.5 → pq = [5, 2.5, 2.5]
// After k = 2 operations, pq.top() = 5
// But let’s think: you can split the 10-unit gap into 3 equal parts: 3.33, 3.33, 3.33

// arr = [1, 13, 17, 23], k = 5
// pq -> {1, 13} -> 12
//       {13, 17} -> 4
//       {17, 23} -> 6
// now we can place 5 stations in between them
// {1, 13} -> 12 -> 6 / 1 -> 4 / 2 -> 3 / 3
// {13, 17} -> 4 -> 4 ->  2 / 1
// {17, 23} -> 6 -> 3 / 1
// here the max distance is 3
// priorty queue can solve it 

// imp
// striver's solution 
// here the stations will be played inside of the stations ....
// not the best approach
double findSmallestMaxDist(vector<int> &stations, int k) {
    priority_queue<pair<pair<double, int>, pair<int, int>>> pq;
    for(int i=1; i<stations.size(); i++){
        pq.push({{stations[i] - stations[i-1], 0}, {stations[i-1], stations[i]}});
    }

    while(k > 0){
        int start = pq.top().second.first;
        int end = pq.top().second.second;
        int noOfStations = pq.top().first.second;
        int internal_gaps = pq.top().first.second + 1;
        int o_dist = end - start;
        pq.pop();
        // there is some error in sorting by priority queue due to double 
        pq.push({{double(o_dist) / double(internal_gaps + 1), noOfStations + 1}, {start, end}});
        k--;
    }

    return pq.top().first.first;
}


// vector<int> ..... gas stations
// [0, 0, 0]
// time complexity o(N*K)
// space complexity o(N)*2
// this will give Time limit exceeded .....
double minimiseMaxDistance(vector<int> &stations, int k){
	vector<double> dist(stations.size()-1);
    vector<int> count(stations.size()-1, 0);

    for(int i=1; i<stations.size(); i++) dist[i-1] = stations[i] - stations[i-1];

    for(int i=0; i<k; i++){
        double maxi = 0.0;
        int index;
        for(int j=0; j<stations.size()-1; j++){
            if(dist[j] > maxi){
                index = j;
                maxi = dist[j];
            }
        }

        dist[index] = double(stations[index + 1] - stations[index]) / (count[index] + 2);
        count[index] = count[index] + 1;
    }

    double maxi = 0.0;
    for(int i=0; i<dist.size(); i++) {
        if(dist[i] > maxi){
            maxi = dist[i];
        }
    }
    return maxi;	
}



// time complexity o(N) * priortiy queue time complexity log(N)
// space complexity o(N)*2
double minimiseMaxDistance(vector<int> &stations, int k){
	vector<double> dist(stations.size()-1);
    vector<int> count(stations.size()-1, 0);
    priority_queue<pair<double, int>> pq;

    for(int i=1; i<stations.size(); i++) {
        dist[i-1] = stations[i] - stations[i-1];
        pq.push({dist[i-1], i-1});
    }

    for(int i=0; i<k; i++){
        double maxi = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        dist[index] = double(stations[index + 1] - stations[index]) / (count[index] + 2);
        count[index] = count[index] + 1;
        pq.push({dist[index], index});
    }

    double maxi = 0.0;
    for(int i=0; i<dist.size(); i++) {
        if(dist[i] > maxi){
            maxi = dist[i];
        }
    }
    return maxi;	
}
