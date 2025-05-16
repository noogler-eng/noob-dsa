// Lemonade Change

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.

// At a lemonade stand, each lemonade costs $5
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int no_of_five = 0;
        int no_of_ten = 0;
        int no_of_twenty = 0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) no_of_five++;
            else if(bills[i] == 10){
                if(no_of_five > 0){
                    no_of_five--;
                    no_of_ten++;
                }else return false;
            }else {
                if(no_of_ten > 0 && no_of_five > 0){
                    no_of_ten--;
                    no_of_five--;
                }else if(no_of_ten == 0 && no_of_five >= 3){
                    no_of_five-=3;
                }else return false;
            }
        }
        return true;
    }
};