// Maximum Product Of Any Two Digits
// https://leetcode.com/contest/weekly-contest-448/problems/maximum-product-of-two-digits/description/?slug=fill-a-special-grid&region=global_v2
// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int maxProduct(int n) {
        int highOne = INT_MIN, highTwo = INT_MIN;
        while(n > 0){
            int digit = n % 10;
            if(digit > highOne){
                highTwo = highOne;
                highOne = digit;
            }else if(digit > highTwo){
                highTwo = digit;
            }
            n = n / 10;
        }

        return highOne * highTwo;
    }
};©leetcode