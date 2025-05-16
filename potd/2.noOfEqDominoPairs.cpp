// Number Of Equivalent Dominos Pairs

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        for (int i = 0 ; i < dominoes.size() ; i++) {
            for (int j = i + 1 ; j < dominoes.size() ; j++) {
                int a = dominoes[i][0], b = dominoes[i][1];
                int c = dominoes[j][0], d = dominoes[j][1];
                if ((a == c && b == d) || (a == d && b == c))
                ++count;
            }
        }
        return count;
    }
};

// efficent way
// time complexity o(N)
// space complexity o(N)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int count = 0;
        for(int i=0; i<dominoes.size(); i++){
            int x = min(dominoes[i][0], dominoes[i][1]);
            int y = max(dominoes[i][0], dominoes[i][1]);
            int val = (x * 10) + y;
            count += m[val];
            m[val]++;      
        }
        return count;
    }
};