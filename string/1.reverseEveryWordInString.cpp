// Reverse every word in string

#include<iostream>
using namespace std;

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.

// Input: s = "the sky is blue"
// Output: "blue is sky the"

#include<iostream>
#include <sstream>
#include<string>
using namespace std;

// time complexity o(N)
// space complexity o(N)
string reverse_every_word_in_string(string s){
    // this will take whole string into words and break it into words internally
    stringstream str(s);
    string word;
    string temp = "";
    stack<string> st;

    while(str >> word){
        st.push(word);
    }   

    while(!st.empty()){
        temp+=st.top();
        st.pop();
        temp+=" ";
    }

    temp.pop_back();
    return temp;
}