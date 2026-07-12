class Twitter {
public:

    struct Tweet{
        int order;
        int userId;
        int tweetId;
    };
    struct Cmp{
        bool operator()(const Tweet& t1, const Tweet& t2) {
            return t1.order < t2.order;
        }
    };

    unordered_map<int, unordered_map<int, bool>> follows;

    priority_queue<Tweet, vector<Tweet>, Cmp> pq;

    int tweetOrder = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({tweetOrder, userId, tweetId});
        tweetOrder++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        queue<Tweet> temp;
        while(!pq.empty() && feed.size() < 10) {
            Tweet top = pq.top();
            pq.pop();
            if(follows[userId][top.userId] || top.userId == userId) {
                feed.push_back(top.tweetId);
            }
            temp.push(top);
        }
        while(!temp.empty()){
            pq.push(temp.front());
            temp.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = false;
    }
};
