class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1)max_area=max(max_area, areaOfIsland(grid, i, j));
            }
        }
        return max_area;
    }
    int areaOfIsland(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)return 0;
        int ans=1;
        grid[i][j]=0;
        ans += areaOfIsland(grid, i-1, j);
        ans += areaOfIsland(grid, i+1, j);
        ans += areaOfIsland(grid, i, j-1);
        ans += areaOfIsland(grid, i, j+1);
        return ans;
    }
};