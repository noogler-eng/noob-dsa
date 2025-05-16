// Job Sequencing Problem

// Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. 
// The profit can only be earned upon completing the job within its deadline. Find the number of 
// jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only 
// one job can be performed at a time.

// Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output: 2 60

// sort according to the deadline, then sort on the basis of profit

#include<iostream>
using namespace std;

// time complexity o(N*M)
// space complexity o(N)
pair<int, int> maximum_profit_on_completion_of_job(vector<vector<int>> jobs){
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b){
        return a[2] > b[2];
    });

    int max_deadline = 0;
    for(int i=0; i<jobs.size(); i++) max_deadline = max(max_deadline, jobs[i][1]);
    
    int profit = 0;
    int count = 0;
    vector<int> slot(max_deadline + 1, 0);

    // we are cheking if any of the slot is remained vacant
    for(int i=0; i<jobs.size(); i++){
        int deadline = jobs[i][1];
        for (int j = deadline; j >= 1; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                profit += jobs[i][2];
                count++;
                break;
            }
        }
    }

    return {count, profit};
}
