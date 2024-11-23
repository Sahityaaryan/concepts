#include<bits/stdc++.h>
using namespace std;
 

class Twitter {
public:
    map<int, vector<pair<int, int>>> posts;
    map<int, set<int>> followers;
    int postId = 0;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({postId, tweetId});
        postId++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed = posts[userId];
       
        for (auto it : followers[userId]) {
            vector<pair<int, int>> temp = posts[it];
            cout << temp.size() << endl;

            feed.insert(feed.end(), temp.begin(), temp.end());
        }

        sort(feed.begin(), feed.end(),
             [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                 return a.first > b.first;
             });
        vector<int> output;
        for (auto it : feed) {

            output.push_back(it.second);
        }
        if (output.size() > 10)
            return vector<int>(output.begin(), output.begin() + 10);
        return output;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto pt=find(followers[followerId].begin(), followers[followerId].end(),
                  followeeId);
        if (pt !=followers[followerId].end() )
            followers[followerId].erase(pt);
    }
};










class Data{
    public:
    
    int val;
    int apos;
    int vpos;
    int validId;

    Data(int va, int a, int v, int vid){
        val = va;
        apos = a;
        vpos = v;
        validId = vid;
    }
};

struct myComp{
    bool operator()(Data& d1, Data& d2){
        return d1.val > d2.val;
    }
};

class Twitter {

public:
    unordered_map<int, set<int>> follower_relation;
    unordered_map<int, vector<pair<int , int>>> news;

    int postId = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        // cout << "tweeting ; " << postId << " " << tweetId << '\n';
        news[userId].push_back({postId ,tweetId});
        postId++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<pair<int, int>> recentNews;

        if(news.find(userId) != news.end()){
            recentNews = news[userId];
        }

        for(auto i :follower_relation[userId]){
            if(news.find(i) != news.end()){
                 vector<pair<int, int>> temp = news[i];
                 recentNews.insert(recentNews.end(), temp.begin(), temp.end());
            }
        }

        sort(recentNews.begin(), recentNews.end(), [](const pair<int,int>& a, const pair<int,int>& b)->bool{
            return a.first > b.first;
        }); 

        vector<int> userFeed;

        for(auto ele:recentNews){
            userFeed.emplace_back(ele.second);

            if(userFeed.size() == 10){
                return userFeed;
            }
        }

        return userFeed;
    }
    
    void follow(int followerId, int followeeId) {
        follower_relation[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        if(follower_relation[followerId].find(followeeId) != follower_relation[followerId].end()){
            follower_relation[followerId].erase(followeeId);
        }
    }
};












int main(){
    
 cout << endl;
return 0;
}