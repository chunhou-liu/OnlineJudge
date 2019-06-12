#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size()<3)return A.size();
        vector<unordered_map<int,int>> dp(A.size());
        vector<int> dp2(A.size(), 0);
        int res = 0;
        for(int i=A.size()-2; i>=0; --i){
            for(int j=i+1; j<A.size(); ++j){
                int diff = A[j]-A[i],
                    cur = dp[i].find(diff)==dp[i].end()?0:dp[i][diff],
                    upd = dp[j].find(diff)==dp[j].end()?2:dp[j][diff]+1;
                dp[i][diff] = max(cur, upd);
                res = max(res, dp[i][diff]);
            }
        }
        return res;
    }
};