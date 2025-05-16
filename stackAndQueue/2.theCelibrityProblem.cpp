// The Celibrity Problem

#include<iostream>
using namespace std;

bool knows(int a, int b) {}

int findCelebrity(int n) {
	// A celebrity is a person who is known to everyone  
	// does not know anyone at the party
	// (A, B) means A knows B [true]

	// brute force approacs
    // time complexity: O(n^2)
    // space complexity: O(1)
	for(int i=0; i<n; i++){
		int j=0;
		for(j=0; j<n; j++){
			if(j == i) continue;
            // if A knows B, then A is not a celebrity
            // knows(i, j) inbuilt function
			if(knows(i, j) != false || knows(j, i) != true) break;
		}
		if(j == n) {
			return i;
		}
	}
	return -1;
}


// optmised approach
// time complexity o(N)
//  important question ----- 
int findCelebrity(int n) {
    int candidate = 0;

    // Step 1: Find the celebrity candidate
    for (int i = 1; i < n; i++) {
        if (knows(candidate, i)) {
            // candidate knows i, so candidate can't be celebrity
            candidate = i;
        }
        // else: i cannot be a celebrity
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        // candidate must not know i, and everyone must know candidate
        if (knows(candidate, i) || !knows(i, candidate)) {
            return -1;
        }
    }

    return candidate;
}