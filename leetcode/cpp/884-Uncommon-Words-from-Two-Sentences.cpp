#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hash1, hash2;
        vector<string> ans;
        int prev = -1;
        for(int cur=0;cur<A.size();++cur){
            if(A[cur]==' '){
                string sub = A.substr(prev+1, cur-prev-1);
                if(hash1.find(sub)!=hash1.end()){
                    hash1[sub]+=1;
                }else hash1[sub]=1;
                prev=cur;
            }
        }       
        string sub = A.substr(prev+1, A.size()-prev-1);
        if(hash1.find(sub)!=hash1.end())hash1[sub]+=1;
        else hash1[sub]=1;

        prev = -1;
        for(int cur=0;cur<B.size();++cur){
            if(B[cur]==' '){
                string sub = B.substr(prev+1, cur-prev-1);
                if(hash2.find(sub)!=hash2.end()){
                    hash2[sub]+=1;
                }else hash2[sub]=1;
                prev=cur;
            }
        }
        sub = B.substr(prev+1, B.size()-prev-1);
        if(hash2.find(sub)!=hash2.end())hash2[sub]+=1;
        else hash2[sub]=1;
        for(unordered_map<string, int>::iterator i=hash1.begin();i!=hash1.end();++i){
            if(i->second==1 && hash2.find(i->first)==hash2.end())ans.push_back(i->first);
        }
        for(unordered_map<string, int>::iterator i=hash2.begin();i!=hash2.end();++i){
            if(i->second==1 && hash1.find(i->first)==hash1.end())ans.push_back(i->first);
        }
        return ans;
    }
};