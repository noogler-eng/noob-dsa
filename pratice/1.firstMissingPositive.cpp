// First Missing Positive 
// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
#include<iostream>
#include<unordered_set>
using namespace std;

// You are given an integer array arr. Your task is to find the smallest 
// positive number missing from the array.
// Note: Positive number starts from 1. The array can have negative integers too.

// brute forcecheck each positive number from 1 to N
// if any of not found then return immediately
// time complexity o(N*N)
// space complexity o(1)

// time complexity o(NlogN + N)
// space complexity o(1)
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int count = 1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > 0 && arr[i] != count){
                return count;
            }else if(arr[i] > 0 && arr[i] == count){
                if(i < arr.size()-1 && arr[i] != arr[i+1]){
                    count++;
                }else if(i == arr.size()-1) count++;
            }
        }

        return count;
    }
};


// we can use it by using set, check if the element is present or not
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        unordered_set<int> s;
        for(int i=0; i<arr.size(); i++) s.insert(arr[i]);
        for(int i=1; i<=arr.size(); i++){
            if(s.find(i) == s.end()) return i;
        }

        return arr.size()+1;
    }
};

