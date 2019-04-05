#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0 || image[0].size()==0)return image;
        int m=image.size(), n=image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(image, sr, sc, image[sr][sc], newColor, visited);
        return image;
    }
    void dfs(vector<vector<int>> &image, int i, int j, int target, int newColor, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || visited[i][j] || image[i][j]!=target)return;
        image[i][j] = newColor;
        visited[i][j]=true;
        dfs(image, i-1, j, target, newColor, visited);
        dfs(image, i+1, j, target, newColor, visited);
        dfs(image, i, j-1, target, newColor, visited);
        dfs(image, i, j+1, target, newColor, visited);
    }
};