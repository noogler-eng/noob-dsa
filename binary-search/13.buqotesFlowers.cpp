// Minimum number of days to make m bouquets with k flowers each

#include<iostream>
using namespace std;

// pattern: binary search, use when the answer is in a range (sorted)
// time complexity: O(nlog(maxi)), where n is the size of bloomDay and maxi is the maximum value in bloomDay
// space complexity: O(1)
class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid){
        int j = 0, count = 0;
        while(j < bloomDay.size()){
            if(bloomDay[j] <= mid){
                count++;
                if(count == k){
                    m--;
                    count = 0;
                }
            } else {
                count = 0;
            }
            j++;
        }

        if(m <= 0) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = 0;
        if((long long)m * k > bloomDay.size()) return -1;
        for(int i=0; i<bloomDay.size(); i++) maxi = max(maxi, bloomDay[i]);
        
        int low = 0, high = maxi, ans = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};