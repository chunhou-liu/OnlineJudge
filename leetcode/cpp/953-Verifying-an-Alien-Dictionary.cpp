#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        static const string std_alpha("abcdefghijklmnopqrstuvwxyz");
        unordered_map<char, char> hash;
        for(int i=0;i<26;++i){
            hash[order[i]]=std_alpha[i];
        }
        vector<string> earth;
        for(auto &word : words)
            earth.push_back(translate(word, hash));
        for(int i=0;i<earth.size();++i){
            for(int j=0;j<i;++j)
                if(earth[j]>earth[i])return false;
        }
        return true;
    }
    string translate(string &alien, unordered_map<char, char> &dict){
        string ans;
        for(int i=0;i<alien.size();++i)ans.push_back(dict[alien[i]]);
        return ans;
    }
};