// Missing Element In Ap

// Given a sorted array arr[] that represents an Arithmetic Progression (AP) 
// with exactly one missing element, find the missing number.

// Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression.
// If the given sequence already forms a valid complete AP, return the (n+1)-th element that would 
// come next in the sequence.

#include<iostream>
using namespace std;

// Input: arr[] = [2, 4, 8, 10, 12, 14]
// time complexity o(N) * 2
// space complexity o(1)
class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int count = 0;
        int diff = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] - arr[i-1] == diff){
                count++;
                if(count > 2) break;
            }else{
                count = 1;
                diff = arr[i] - arr[i-1];
            }
        }

        int missing = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] + diff != arr[i+1]){
                return arr[i] + diff;                
            }
        }

        return arr[arr.size()-1] + diff;
    }
};