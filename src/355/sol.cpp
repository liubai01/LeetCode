#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

#define DEBUG true

using namespace std;

class Tweet {
public:
    int date;
    int id;
    Tweet(int date, int id) {
        this->date = date;
        this->id = id;
    }
};

class User {
public:
    int userId;

    vector<User*> followers;
    vector<User*> followees;
    vector<Tweet*> tweets;

    unordered_map<int, User*> id2followers;
    unordered_map<int, User*> id2followees;

    User(int userId) {
        this->userId = userId;

        id2followers = {};
        id2followees = {};
    }

    void addFollowers(int userId, User* user) {
        if (id2followers.find(userId) == id2followers.end()) {
            // user not in follower now
            id2followers[userId] = user;
            followers.push_back(user);
        }
    }

    void addFollowee(int userId, User* user) {
        if (id2followees.find(userId) == id2followees.end()) {
            // user not in follower now
            id2followees[userId] = user;
            followees.push_back(user);
        }
    }

    void removeFollowers(int userId, User* user) {
        if (id2followers.find(userId) != id2followers.end()) {
            id2followers.erase(userId);
        }
        for (auto iter = followers.begin(); iter != followers.end(); ++iter) {
                if ((*iter)->userId == userId) {
                    followers.erase(iter);
                    break;
                }
        }
    }

    void removeFollowee(int userId, User* user) {
        if (id2followees.find(userId) != id2followees.end()) {
            id2followees.erase(userId);
        }
        for (auto iter = followees.begin(); iter != followees.end(); ++iter) {
                if ((*iter)->userId == userId) {
                    followees.erase(iter);
                    break;
                }
        }
    }

};

class Twitter {
public:
	unordered_map<int, User*> id2user;
    unordered_map<int, Tweet*> id2tweet;

    int date_cnter;

    /** Initialize your data structure here. */
    Twitter() {
    	id2user = {};
        date_cnter = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // check the uniquity of tweet id
        if (existTweet(tweetId)) {
            if (DEBUG) cout << "Tweet exits: " << tweetId << endl;
            return;
        }
    	User* u = createOrGetUser(userId);
        Tweet* t = createTweet(tweetId);

        u->tweets.insert(u->tweets.begin(), t);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        User* u = createOrGetUser(userId);
        int recvMsgUsersNum = u->followees.size() + 1;
        vector<Tweet*>::iterator tgtTweets[recvMsgUsersNum][2];
        vector<int> retTweetsIds;
        priority_queue<pair<int, int>> pq; // (tweet_date, idx for tgtTweets)
        int retTweetsNum = 0;

        int i = 1;

        tgtTweets[0][0] = u->tweets.begin();
        tgtTweets[0][1] = u->tweets.end();

        for (auto iter = u->followees.begin(); iter != u->followees.end(); ++iter) {
            User* u_f = *iter;
            tgtTweets[i][0] = u_f->tweets.begin();
            tgtTweets[i][1] = u_f->tweets.end();
            ++i;
        }

        // initialize 
        for(i = 0; i < recvMsgUsersNum; ++i) {
            if (tgtTweets[i][0] != tgtTweets[i][1]) {
                pq.push(pair<int, int>((*tgtTweets[i][0])->date, i));
            }
        }

        while (retTweetsNum < 10 && !pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            vector<Tweet*>::iterator ut_now = tgtTweets[p.second][0];
            vector<Tweet*>::iterator ut_end = tgtTweets[p.second][1];

            Tweet* t = *ut_now;
            retTweetsIds.push_back(t->id);
            ++retTweetsNum;

            ++ut_now;
            if (ut_now != ut_end) {
                tgtTweets[p.second][0] = ut_now;
                pq.push(pair<int, int>((*ut_now)->date, p.second));
            }

        }
        return retTweetsIds;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            User* u_fer = createOrGetUser(followerId);
            User* u_fee = createOrGetUser(followeeId);

            u_fer->addFollowee(followeeId, u_fee);
            u_fee->addFollowers(followerId, u_fer);

        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        User* u_fer = createOrGetUser(followerId);
        User* u_fee = createOrGetUser(followeeId);

        u_fer->removeFollowee(followeeId, u_fee);
        u_fee->removeFollowers(followerId, u_fer);
    }
private:
	User* createOrGetUser(int userId) {
        if (id2user.find(userId) == id2user.end()) {
            // create a new user if not exists
            User* u = new User(userId);
            id2user[userId] = u;
            return u;
        } 
        // return a current user in database
        return id2user[userId];
    }
    Tweet* createTweet(int tweetId) {
        if (id2tweet.find(tweetId) == id2tweet.end()) {
            // Create a new tweet if not exits
            Tweet* t = new Tweet(date_cnter, tweetId);
            // Update the date counter
            date_cnter += 1; 
            id2tweet[tweetId] = t;
            return t;
        }
        // return null pointer if there is a collision of tweet
        return nullptr;
    }
    bool existTweet(int tweetId) {
        if (id2tweet.find(tweetId) == id2tweet.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */