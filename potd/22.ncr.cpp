// find ncr
// https://www.geeksforgeeks.org/problems/ncr1019/1

#include<iostream>
using namespace std;
// time complexity o(r)
// space complexity o(1)
class Solution {
  public:
    int nCr(int n, int r) {
        if(r > n) return 0;
        if(r == 0 || r == n) return 1;
    
        // as ncr == ncn-r
        if(r > n-r) r = n-r;
        
        long long ans = 1;
        for(int i=1; i<=r; i++){
            ans = ans * (n - r + i);
            ans = ans / i;
        }
        
        return int(ans);
    }
};
