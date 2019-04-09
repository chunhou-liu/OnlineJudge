#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<string> subStk;
        stack<int> repStk;
        int cur_index = 0, repeat=0;
        while(cur_index<s.size()){
            if(isdigit(s[cur_index])){
                repeat *= 10;
                repeat += s[cur_index] - '0';
                ++cur_index;
                continue;
            }
            if(s[cur_index]=='['){
                repStk.push(repeat);
                repeat = 0;
                subStk.push(res);
                res = "";
                ++cur_index;
                continue;
            }
            if(s[cur_index]==']'){
                int cur_repeat = repStk.top(); repStk.pop();
                string tmp = res;
                for(;cur_repeat>1;--cur_repeat){
                    tmp += res;
                }
                res = subStk.top() + tmp; subStk.pop();
                ++cur_index;
                continue;
            }
            res.push_back(s[cur_index]);
            ++cur_index;
        }
        return res;
    }
};