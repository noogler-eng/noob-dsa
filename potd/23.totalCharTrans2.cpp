// Total Character Transformation After T Length 

#include<iostream>
using namespace std;

// time complexity o(t * 26 * N)
// space complexity o(2N)
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int mod = 1000000000 + 7;
        vector<long long> freq(26, 0);
        for(int i=0; i<s.length(); i++) freq[s[i] - 'a']++;
        int count = s.length() % mod;

        for(int i=0; i<t; i++){
            vector<long long> newFreq(26, 0);
            for(int j=0; j<26; j++){
                if(freq[j] == 0) continue;
                
                for(int k=1; k<=nums[j]; k++){
                    int nextChar = (j + k) % 26;
                    newFreq[nextChar] = (newFreq[nextChar] + freq[j]) % mod;
                }
            }
            freq = newFreq;
        }

        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % mod;
        }

        return total;
    }
};


// optmised version
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int mod = 1000000000 + 7;
        vector<long long> freq(26, 0);
        for(int i=0; i<s.length(); i++) freq[s[i] - 'a']++;
        int count = s.length() % mod;

        for(int i=0; i<t; i++){
            vector<long long> newFreq(26, 0);
            for(int j=0; j<26; j++){
                if(freq[j] == 0 || nums[j] == 0) continue;

                int start = (j+1) % 26;
                
                
                for(int k=1; k<=nums[j]; k++){
                    int nextChar = (j + k) % 26;
                    newFreq[nextChar] = (newFreq[nextChar] + freq[j]) % mod;
                }
            }
            freq = newFreq;
        }

        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % mod;
        }

        return total;
    }
};