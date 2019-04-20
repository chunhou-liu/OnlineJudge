#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)return 0;
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int zero_count = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
                if(grid[i][j]==0)++zero_count;
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1)return dfs(grid, i, j, visited, zero_count);
            }
        }
        return 0;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int &zero_count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==-1)return 0;
        if(grid[i][j]==2)return zero_count==0?1:0;
        visited[i][j] = true;
        if(grid[i][j]==0)--zero_count;
        int left = dfs(grid, i, j-1, visited, zero_count),
            right = dfs(grid, i, j+1, visited, zero_count),
            up = dfs(grid, i-1, j, visited, zero_count),
            down = dfs(grid, i+1, j, visited, zero_count);
        visited[i][j] = false;
        if(grid[i][j]==0)++zero_count;
        return left + right + up + down;
    }
};