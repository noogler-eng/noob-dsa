// N Meetig In Rooms
// Problem Statement: There is one meeting room in a firm. 
// You are given two arrays, start and end each of size N.For an index ‘i’, start[i] 
// denotes the starting time of the ith meeting while end[i]  will denote the ending time 
// of the ith meeting. Find the maximum number of meetings that can be accommodated if only 
// one meeting can happen in the room at a  particular time. Print the order in which these 
// meetings will be performed.

// Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

#include<iostream>
using namespace std;

int no_of_meetings(vector<int> start, vector<int> end){
    vector<pair<int, int>> m;
    for(int i=0; i<start.size(); i++) m.push_back({end[i], start[i]});
    sort(m.begin(), m.end());

    int count = 0, last_end_time = 0;
    while(int i=0; i<start.size(); i++){
        if(m[i].second > last_end_time) {
            count++;
            last_end_time++;
        }
    }
    return count;
}