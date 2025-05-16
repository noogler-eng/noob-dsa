// Sort Characters By Freq

// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

#include<iostream>
using namespace std;

// time complexity o(N)*3
// space complexity o(N*2)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++) m[s[i]]++;
        vector<pair<char, int>> v;
        
        for(auto i: m){
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b){
            return a.second < b.second;
        });

        string temp = "";
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].second; j++){
                temp += v[i].first;
            }
        }
        return temp;
    }
};