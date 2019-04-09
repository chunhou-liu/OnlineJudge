class Solution {
public:
    string customSortString(string S, string T) {
        string ans;
        for(auto c:S){
            int cnt=count(T.begin(), T.end(), c);
            for(int i=0;i<cnt;++i)ans.push_back(c);
        }
        for(auto c:T){
            if(S.find(c)==S.npos)ans.push_back(c);
        }
        return ans;
    }
};