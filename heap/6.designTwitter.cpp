// Design Twitter

#include<iostream>
#include<unordered_set>
using namespace std;

// time complexity o(N)
// space complexity o(N) * 3
class Twitter {
public:
    unordered_map<int, unordered_set<int>> u;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp;
    Twitter() {
        this->timestamp = 0;
    }
    
    // time complexity o(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }

    
    // time complexity o(N);
    // where N is total number of tweets
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> followeeList = u[userId];
        followeeList.insert(userId);

        for(int user: followeeList){
            auto &tw = tweets[user];
            int count = 10;
            for(int i = max(0, (int)tw.size() - 10); i<tw.size(); i++){
                pq.push({tw[i].first, tw[i].second}); 
            }
        }

        vector<int> ans;
        while(!pq.empty() && ans.size() != 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    // time complexity o(1)
    void follow(int followerId, int followeeId) {
        u[followerId].insert(followeeId);
    }
    
    // time complexity o(1)
    void unfollow(int followerId, int followeeId) {
        u[followerId].erase(followeeId);
    }
};
