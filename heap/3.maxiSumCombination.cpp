// Max Sum Combination
// Given two integer array A and B of size N each.
// A sum combination is made by adding one element 
// from array A and another element of array B.
// Return the maximum K valid sum combinations from 
// all the possible sum combinations.

// important question ----- 
// nice concept ----

#include<iostream>
#include<set>
using namespace std;

// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// pq = 4 + 3, 4 + 2

// 1 4 2 3 -> 4
// 2 5 1 6 -> 6

// time complexity o(N*N) + o(LogN)*N^2
// space complexity o(N), not including ans vector space
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    priority_queue<int> pq; 

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            pq.push(A[i] + B[j]);
        }
    }

    vector<int> temp;
    while(!pq.empty() && K > 0){
        temp.push_back(pq.top());
        pq.pop();
        K--;
    }
   
    return temp;
}


// optmised version 
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// sort - {4, 3, 2, 1}
// sort - {6, 5, 2, 1}
// time complexity o((N+M)log(N)) + NlogN + MlogM
// space complexity o(N+M) * 2
// this is more optmised as same approach which i thought correct code for that
// time complexity o(NlogN) * 2 + 2 * KlogK
// space compexity o(K)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // hold possible all the summations
    priority_queue<pair<int, pair<int, int>>> pq;
    // check if we already visited that i and j
    set<pair<int, int>> visited;
    vector<int> temp;

    pq.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});

    while(K > 0 && !pq.empty()){
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        temp.push_back(sum);
        K--;

        // increasing i then check
        if(i + 1< A.size() && visited.find({i+1, j}) == visited.end()){
            pq.push({A[i+1] + B[j], {i+1, j}});
            visited.insert({i+1, j});
        } 

        // increasing j then check
        if(j + 1< B.size() && visited.find({i, j+1}) == visited.end()){
            pq.push({A[i] + B[j+1], {i, j+1}});
            visited.insert({i, j+1});
        } 
    }

    return temp;
}
