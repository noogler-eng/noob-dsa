// Push Dominoes
// https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02

#include<iostream>
using namespace std;

// time complexity o(N)*3
// space complexity o(N)
class Solution {
public:
    string pushDominoes(string dominoes) {
        // .L.R...LR..L..
        // 00001010010000
        // 10001010001000

        // RR.L
        // 0111
        // 0010
        // RRRL

        int n = dominoes.size();
        vector<int> move(dominoes.size(), 0);

        int force = 0;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                force = n;
            }else if(dominoes[i] == 'L'){
                force = 0;
            }else{
                force = max(force - 1, 0);
            }
            move[i] = force;
        }

        force = 0;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L'){
                force = n;
            }else if(dominoes[i] == 'R'){
                force = 0;
            }else{
                force = max(force-1, 0);
            }
            move[i] -= force;
        }

        for(int i=0; i<n; i++){
            if(dominoes[i] == '.'){
                if(move[i] > 0){
                    dominoes[i] = 'R';
                }else if(move[i] < 0){
                    dominoes[i] = 'L';
                }
            }
        }

        return dominoes;
    }
};