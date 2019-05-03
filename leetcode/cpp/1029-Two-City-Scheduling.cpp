#include <vector>
using namespace std;


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int dp[n+1][n+1]; // dp[i][j] : minimum cost when there are i people and choose j to A
        dp[0][0]=0;
        for(int i=1;i<=n;++i){
            dp[i][0] = dp[i-1][0] + costs[i-1][1];
            dp[i][i] = dp[i-1][i-1] + costs[i-1][0];
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<i; ++j){
                dp[i][j] = min(dp[i-1][j] + costs[i-1][1], dp[i-1][j-1]+costs[i-1][0]);
            }
        }
        return dp[n][n/2];
    }
};