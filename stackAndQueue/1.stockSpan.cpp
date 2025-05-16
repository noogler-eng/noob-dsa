// Online Stock Span

#include<iostream>
using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class StockSpanner {
public:
    stack<pair<int, int>> st;
    // {100, 1}
    // {80, 1}
    // {75, 4}
    // {85, 6}
    StockSpanner() {}
    
    int next(int price) {
        int val = 1;
        while(!st.empty()){
            if(st.top().first <= price){
                val += st.top().second;
                st.pop();
            }else {
                st.push({price, val});
                break;
            }
        }

        if(st.empty()) st.push({price, val});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */