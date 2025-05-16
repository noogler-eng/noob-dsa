// Hands Of Straight
// https://leetcode.com/problems/hand-of-straights/description/
// Divide Arry In Sets Of K Consecutive Numbers
// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
// both question are same


// Alice has some number of cards and she wants to rearrange the cards into 
// groups so that each group is of size groupSize, and consists of groupSize 
// consecutive cards.
// Given an integer array hand where hand[i] is the value written on the ith 
// card and an integer groupSize, return true if she can rearrange the cards, 
// or false otherwise.

#include<iostream>
#include<map>
using namespace std;

// hand = [1,2,3,6,2,3,4,7,8]
// hand = [1,2,2,3,3,4,6,7,8]
// here now we have to make the groups of K
// [1,2,3], [2,3,4], [6,7,8]
// 1 -> 1       0
// 2 -> 2       1       0
// 3 -> 2       1       0
// 4 -> 1               0
// 6 -> 1                       0
// 7 -> 1                       0
// 8 -> 1                       0

// nice and important question
// time complexity o(N) * 2, traversing all element
// space complexity o(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        // Sorted by keys in ascending order by default
        // not by values, it is sorted by keys
        map<int, int> m;
        for(int i=0; i<hand.size(); i++) m[hand[i]]++;
        
        // we will move to the starting point then remove its 
        // 3 keys, then again move to the starting point
        for(auto i: m){
            int number = i.first;
            int freq = i.second;
            if(freq > 0){
                for(int j=0; j<groupSize; j++){
                    if(m[number + j] < freq) return false;
                    m[number + j] -= freq;
                }
            }
        }
        return true;
    }
};