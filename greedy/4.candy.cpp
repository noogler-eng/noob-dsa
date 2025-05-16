// Candy
// https://leetcode.com/problems/candy/description/

// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

#include<iostream>
using namespace std;

// Input: ratings = [1,0,2]
// left [1, 1, 2]
// right [2, 1, 1]
// taking the maxi of both [2, 1, 2] for satisfying the condition

// [1,2,2]
// [1, 2, 2] left
// [0, 1, 1] right
// [1, 2, 2]

// time complexity o(3N)
// space complexity o(2N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // from the perspective of left
        for(int i=0; i<n; i++){
            if((i == 0) || ratings[i] <= ratings[i-1]){
                left[i] = 1;
            }else{
                left[i] = left[i-1] + 1;
            }
        }

        // from the perspective of right
        for(int i=n-1; i>=0; i--){
            if((i == n-1) || ratings[i] <= ratings[i+1]){
                right[i] = 1;
            }else{
                right[i] = right[i+1] + 1;
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            count += max(left[i], right[i]);
        }

        return count;
    }
};