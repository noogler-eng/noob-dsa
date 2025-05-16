// Maximum Nesting Depth Of Paranthesis

// Input: s = "(1+(2*3)+((8)/4))+1"
#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(N)
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                maxi = max(maxi, (int)st.size());
            }else if(s[i] == ')'){
                st.pop();
            }
        }
        return maxi;
    }
};
