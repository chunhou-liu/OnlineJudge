#include <string>
#include <iostream>
#include <set>
using namespace std;


bool wordBreak(const string &s, set<string> &dict){
    int n=s.size();
    bool dp[s.size()];
    for(int end=0;end<n;++end){
        dp[end]=false;
        for(int start=0;start<=end;++start){
            string substr = s.substr(start, end-start+1);
            if(dict.find(substr)==dict.end())continue;
            if(start==0 || dp[start-1]){
                dp[end]=true;break;
            }
        }
    }
    return dp[n-1];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        set<string> dict;
        string s;
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>s;
            dict.insert(s);
        }
        cin>>s;
        cout << (wordBreak(s, dict)?1:0) << endl;
    }
    return 0;
}