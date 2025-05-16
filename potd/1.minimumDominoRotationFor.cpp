// Minimum Domino Rotation For Equal Row 
// QUESTION - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/?envType=daily-question&envId=2025-05-03

#include<iostream>
using namespace std;

// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]

// initution - finding all the possible value fro this from 1 to 6
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // possible elements that can fill the either row or col
        unordered_map<int, int> m;
        vector<int> possible;
        for(int i=0; i<tops.size(); i++){
            // both tops and bottom are same then dont count
            if(tops[i] == bottoms[i]) {
                m[tops[i]]++;
                if(m[tops[i]] == tops.size()) possible.push_back(tops[i]);
            }else{
                m[tops[i]]++;
                m[bottoms[i]]++;
                if(m[tops[i]] == tops.size()) possible.push_back(tops[i]);
                if(m[bottoms[i]] == bottoms.size()) possible.push_back(bottoms[i]);
            }
        }

        if(possible.size() == 0) return -1;

        int mini = INT_MAX;
        for(int i=0; i<possible.size(); i++){
            int count = 0;
            for(int j=0; j<tops.size(); j++){
                if(tops[j] != possible[i]) count++;
            }
            mini = min(count, mini);
            count = 0;
            for(int j=0; j<bottoms.size(); j++){
                if(bottoms[j] != possible[i]) count++;
            }
            mini = min(count, mini);
        }

        return mini;
    }
};

// more optmized approach
// as one of the value should be there like 
// either from tops[0] or bottoms[0]
// check both of them
class Solution {
public:
    int checks(int val, vector<int> &a, vector<int> &b){
        int mini_rot_a = 0, mini_rot_b = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != val && b[i] != val) return -1;
            if(a[i] != val) mini_rot_a++;
            if(b[i] != val) mini_rot_b++;
        }
        return min(mini_rot_a, mini_rot_b);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top = tops[0];
        int bottom = bottoms[0];

        int val1 = checks(top, tops, bottoms);
        int val2 = checks(bottom, tops, bottoms);

        if(val1 == -1 && val2 == -1) return -1;
        else if(val1 == -1) return val2;
        else if(val2 == -1) return val1;
        else return min(val1, val2);    
    }
};