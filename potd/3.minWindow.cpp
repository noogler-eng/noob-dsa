// Minimum Window
// https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1

// time complexity o(N) * 2
// space complexity o(N)
class Solution {
  public:
    int findSubString(string& str) {
        int mini = INT_MAX;
        unordered_map<char, int> m;
        for(int i=0; i<str.length(); i++) {
           m[str[i]]++;
        }
        int count = m.size();
        m.clear();

        int i=0, j=0;
        while(j < str.length()){
            m[str[j]]++;

            while(m.size() == count && i <= j){
                mini = min(mini, j-i+1);
                m[str[i]]--;
                if(m[str[i]] == 0) m.erase(str[i]);
                i++;
            }
            j++;
        }

        return mini;
    }
};