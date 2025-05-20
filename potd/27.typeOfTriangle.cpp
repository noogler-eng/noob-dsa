// Type Of Traingle
// https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19
#include<iostream>
using namespace std;

// time complexity: O(1)
// space complexity: O(1)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if(a == 0 || b == 0 || c == 0) return "none";
        if((a + b <= c) || (b + c <= a) ||(c + a <= b)) return "none";

        if(a == b && a == c && b == c){
            return "equilateral";
        }else if(a != b && b != c && c != a){
            return "scalene";
        }else{
            return "isosceles";
        }
    }
};