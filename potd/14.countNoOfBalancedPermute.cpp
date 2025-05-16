// Count Number Of Balanced Permutations

#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isBalanced(string num){
        int odd_sum = 0, even_sum = 0;
        for(int i=0; i<num.length(); i++){
            if(i % 2 == 0) even_sum += num[i] - '0';
            else odd_sum += num[i] - '0';
        }

        return even_sum == odd_sum;
    }

    void helper(string &num, int i, int &ans, unordered_set<string> &s){
        if(i == num.length()) {
            int size = s.size();
            s.insert(num);
            if(s.size() == size) return;
            if(isBalanced(num)) ans += 1;
            return;
        }

        for(int j=i; j<num.length(); j++){
            swap(num[i], num[j]);
            helper(num, i+1, ans, s);
            swap(num[i], num[j]);
        }
    }

    int countBalancedPermutations(string num) {
        // generating all permutations and return which is balanced
        unordered_set<string> s;
        int ans = 0;
        helper(num, 0, ans, s);
        return ans;
    }
};



// optimised
// reoval of duplicates using set for if char is already used or not
class Solution {
public:
    bool isBalanced(string num){
        int odd_sum = 0, even_sum = 0;
        for(int i=0; i<num.length(); i++){
            if(i % 2 == 0) even_sum += num[i] - '0';
            else odd_sum += num[i] - '0';
        }

        return even_sum == odd_sum;
    }

    void helper(string &num, int i, int &ans){
        if(i == num.length()) {
            cout<<num<<endl;
            if(isBalanced(num)) ans += 1;
            return;
        }

        unordered_set<char> used;
        for(int j=i; j<num.length(); j++){
            if(used.count(num[j])) continue;
            used.insert(num[j]);

            swap(num[i], num[j]);
            helper(num, i+1, ans);
            swap(num[i], num[j]);
        }
    }

    int countBalancedPermutations(string num) {
        // generating all permutations and return which is balanced
        int ans = 0;
        sort(num.begin(), num.end());
        helper(num, 0, ans);
        return ans;
    }
};


// more optmised to DP problem
// i don't know this ?? 