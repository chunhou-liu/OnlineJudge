#include <string>
using namespace std;


class Solution {
public:
    string decodeAtIndex(string s, int k) {
        return helper(s, k);
    }
    string helper(string &s, int k){
        if(k==1)return string(1, s[0]);
        long long length = 0;
        for(int i=0; i<s.size();++i){
            if(isalpha(s[i])){
                ++length;
                if(length==k)return string(1, s[i]);
            }else{
                length *= s[i]-'0';
                if(length>=k)return helper(s, (k-1) % (length / (s[i]-'0'))+1);
            }
        }
        return helper(s, (k-1)%length+1);
    }
};