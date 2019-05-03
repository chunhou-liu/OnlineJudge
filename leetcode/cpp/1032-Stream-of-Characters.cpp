#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


class StreamChecker {
    vector<vector<vector<string>>> hash_table;
    vector<bool> chars;
    string query_log;
public:
    StreamChecker(vector<string>& words): hash_table(26, vector<vector<string>>(26)), chars(26, false){
        for(auto &s:words){
            if(s.size()==1)chars[s[0]-'a']=true;
            else hash_table[s.back()-'a'][s[s.size()-2]-'a'].push_back(s);
        }
    }
    
    bool query(char letter) {
        query_log.push_back(letter);
        if(chars[letter-'a'])return chars[letter-'a'];
        vector<string> & dicts = hash_table[letter-'a'][query_log[query_log.size()-2]-'a'];
        for(auto &s: dicts){
            if(s.size()>query_log.size())continue;
            if(s==query_log.substr(query_log.size()-s.size()))return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */