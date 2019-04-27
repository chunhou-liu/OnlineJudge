#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder=="#" || preorder=="")return true;
        stack<int> stk;
        int prev = -1;
        for(size_t cur=0;cur!=preorder.size();++cur){
            if(preorder[cur]==','){
                string tmp = preorder.substr(prev+1, cur-prev-1);
                if(tmp=="#"){
                    if(stk.empty())return false;
                    while(!stk.empty()){
                        ++stk.top();
                        if(stk.top()==2)stk.pop();
                        else break;
                    }
                    if(stk.empty())return false;
                }else{
                    stk.push(0);
                }
                prev=cur;
            }
        }
        string tmp = preorder.substr(prev+1);
        if(tmp=="#"){
            if(stk.empty())return false;
            while(!stk.empty()){
                ++stk.top();
                if(stk.top()==2)stk.pop();
                else break;
            }
        }else{
            stk.push(0);
        }
        return stk.empty();
    }
};