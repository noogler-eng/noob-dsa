// Sum of beauty of all substring

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

// aabcb
// here all its substring
// a, a, b, c, b its eatu is 0

// brute force

#include<iostream>
#include<string>
using namespace std;

// time complexity o(N*N*N)
// space complexity o(N)
int beautySum(string s) {
    int total = 0;
    for(int i=0; i<s.length(); i++){
        unordered_map<int, int> m;
        for(int j=i; j<s.length(); j++){
            m[s[j]]++;
            int mini = INT_MAX, maxi = INT_MIN;
            for(auto k: m){
                mini = min(mini, k.second);
                maxi = max(maxi, k.second);
            }

            total += (maxi - mini);
        }
    }
    return total;
}
