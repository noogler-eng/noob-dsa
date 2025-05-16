// Remove Outermost Paranthesis

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

#include<iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                if(st.size() != 0) ans += '(';
                st.push(s[i]);
            }else{
                if(st.size() == 1){
                    st.pop();
                }else{
                    ans += ')';
                    st.pop();
                }
            }
        }
        return ans;
    }
};