#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string S) {
        stack<char> stk;
        for(int i=0;i<S.size();++i){
            if(S[i]=='a')stk.push(S[i]);
            else if(S[i]=='b'){
                if(stk.size()==0)return false;
                if(stk.top()!='a')return false;
                stk.push(S[i]);
            }else{
                if(stk.size()<2)return false;
                if(stk.top()!='b')return false;
                else{
                    stk.pop();
                    if(stk.top()!='a')return false;
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};