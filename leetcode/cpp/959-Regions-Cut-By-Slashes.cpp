#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N*3, vector<int>(N*3, 0));
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                int base_i = 3*i, base_j = 3*j;
                if(grid[i][j]=='\\'){
                    for(int k=0; k<3; ++k)dp[base_i+k][base_j+k]=1;
                }else if(grid[i][j]=='/'){
                    for(int k=0; k<3; ++k)dp[base_i+k][base_j+2-k]=1;
                }
            }
        }
        int count = 0;
        for(int i=0; i<N*3; ++i){
            for(int j=0; j<N*3; ++j){
                if(dp[i][j]==0){
                    ++count;
                    dfs(dp, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &dp, int i, int j){
        if(i<0 || j<0 || i>=dp.size() || j>=dp.size() || dp[i][j]!=0)return;
        dp[i][j]=-1;
        dfs(dp, i+1, j);
        dfs(dp, i-1, j);
        dfs(dp, i, j+1);
        dfs(dp, i, j-1);
    }
};