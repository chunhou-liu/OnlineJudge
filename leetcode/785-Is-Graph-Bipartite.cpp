#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // color:{0,1}, uncolor:{-1}
        for(int i=0;i<color.size();++i){
            if(color[i]==-1){
                if(!dfs(color, graph, i, 0))return false;
            }
        }
        return true;
    }
    bool dfs(vector<int> &color, vector<vector<int>> &graph, int node, int cur_color){
        if(color[node]!=-1)return color[node]==cur_color;
        color[node] = cur_color;
        bool result = true;
        for(int i=0;i<graph[node].size() && result;++i){
            result = result && dfs(color, graph, graph[node][i], 1-cur_color);
        }
        return result;
    }
};