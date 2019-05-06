#include <vector>
#include <string>
#include <set>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n=A[0].size();
        bool dp[n][n];
        int dp2[n];
        int ans = 1;
        for(int i=0; i<n; ++i){
            dp2[i]=1;
            for(int j=0; j<i; ++j){
                bool cur = true;
                for(int k=0; k<m; ++k)
                    if(A[k][i]<A[k][j])cur=false;
                dp[i][j] = cur;
                if(dp[i][j])dp2[i]=max(dp2[i], dp2[j]+1);
            }
            ans = max(ans, dp2[i]);
        }

        return n - ans;
    }
};