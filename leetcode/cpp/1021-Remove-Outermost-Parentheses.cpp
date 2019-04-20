#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.size()==0)return S;
        string res;
        int d = 1;
        for(int i=1;i<S.size();++i){
            d += S[i]=='('?1:-1;
            if(d!=0)res.push_back(S[i]);
            else{++i;d=1;}
        }
        return res;
    }
};