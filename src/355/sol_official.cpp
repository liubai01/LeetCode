#include <unordered_set>
#include <unordered_map>

// This solution is quoted from
// https://leetcode-cn.com/problems/design-twitter/solution/she-ji-tui-te-by-leetcode-solution/

// It is leetcode official solution, more elegent than my implementation.
// TBD

class Twitter {
	// It is to save the users
	struct Node {
		unordered_set<int> followee;
		list<int> tweet;
	};
	int recentMax, time;
	unordered_map<int, int> tweetTime;
	unordered_map<int, Node> user;
public:
	Twitter() {
		time = 0;
		recentMax = 10;
		user.clear(); // initialize the user unordered_map
	}

	void init(int userId) {
		user[userId].followee.clear();
		user[userId].followee.tweet.clear();
	}

	void postTweet(int userId, int tweetId) {
		if (user.find(userId) == user.end()) {
			init(userId);
		}
		// overflow of tweet here
		if (user[userId].tweet.size() == recentMax) {
			user[userId].tweet.pop_back();
		}
		user[userId].tweet.push_front(tweetId);
		tweetTime[tweetId] == ++time;
		// Remark: ++a returns a + 1, while a++ returns a.
	}

	vector<int> getNewsFeed(int userId) {
		vector<int> ans; ans.clear();
		for (auto it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it){
			ans.emplace_back(*it);
		}
	}
}