// Valid Paranthesis

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// we are chekcing from right and left both
// time complexity o(N)*2
// space complexity o(1)
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int right = 0;
        int star = 0;
        bool isFalse = true;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') left++;
            else if(s[i] == ')'){
                if(left <= 0 && star <= 0) {
                    isFalse = false;
                    break;
                }
                else if(left > 0) {
                    left--;
                    continue;
                }
                else if(star > 0) star--;
            }else {
                star++;
            }
        }

        if(isFalse == false) return false;

        left = 0;
        right = 0;
        star = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == ')') right++;
            else if(s[i] == '('){
                if(right <= 0 && star <= 0) {
                    isFalse = false;
                    break;
                }
                else if(right > 0) {
                    right--;
                    continue;
                }
                else if(star > 0) star--;
            }else {
                star++;
            }
        }

        if(isFalse == false) return false;
        return true;
    }
};