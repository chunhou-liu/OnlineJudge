#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                dfs(matrix, dp, i, j, INT_MIN, visited);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int prev, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || visited[i][j] || matrix[i][j]<=prev)return 0;
        if(dp[i][j]!=0)return dp[i][j];
        visited[i][j] = true;
        int left = dfs(matrix, dp, i, j-1, matrix[i][j], visited),
            right = dfs(matrix, dp, i, j+1, matrix[i][j], visited),
            up = dfs(matrix, dp, i-1, j, matrix[i][j], visited),
            down = dfs(matrix, dp, i+1, j, matrix[i][j], visited);
        dp[i][j] = max(left, max(right, max(up, down))) + 1;
        visited[i][j]=false;
        return dp[i][j];
    }
};