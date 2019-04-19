#include <vector>
using namespace std;


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        // projection onto xy plane
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[i].size();++j)
                if(grid[i][j]!=0)++xy;
        // projection onto yz plane
        // first get highest projection to y
        // for each column get its highest
        vector<int> projection_y;
        vector<int> projection_x(grid.size(), 0);
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(j==projection_y.size())projection_y.push_back(grid[i][j]);
                else projection_y[j] = max(projection_y[j], grid[i][j]);
                projection_x[i] = max(projection_x[i], grid[i][j]);
            }
        }
        for(int i=0;i<projection_y.size();++i)yz+=projection_y[i];
        for(int i=0;i<projection_x.size();++i)zx += projection_x[i];
        return xy + yz + zx;
    }
};