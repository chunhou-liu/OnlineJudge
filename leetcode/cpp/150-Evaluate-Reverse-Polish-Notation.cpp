#include <vector>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int v1, v2;
        for(auto &s : tokens){
            if(isdigit(s.back()))stk.push(stoi(s));
            else{
                switch(s[0]){
                    case '+':
                        v1 = stk.top();stk.pop();
                        v2 = stk.top(); stk.pop();
                        stk.push(v1+v2);
                        break;
                    case '-':
                        v1 = stk.top(); stk.pop();
                        v2 = stk.top(); stk.pop();
                        stk.push(v2-v1);
                        break;
                    case '*':
                        v1 = stk.top(); stk.pop();
                        v2 = stk.top(); stk.pop();
                        stk.push(v1*v2);
                        break;
                    case '/':
                        v1 = stk.top(); stk.pop();
                        v2 = stk.top(); stk.pop();
                        stk.push(v2/v1);
                        break;
                }
            }
        }
        return stk.top();
    }
};