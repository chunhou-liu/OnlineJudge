#include <vector>
using namespace std;


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<bool> visited(n, false);
        for(int i=0;i<stones.size();++i){
            for(int j=i+1;j<stones.size();++j){
                if(stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1]){
                    graph[i][j]=graph[j][i]=true;
                }
            }
        }
        int island_count = 0;
        for(int i=0;i<n;++i){
            if(visited[i])continue;
            dfs(graph, i, visited);
            ++island_count;
        }
        return n - island_count;
    }
    void dfs(vector<vector<bool>> &graph, int k, vector<bool> &visited){
        visited[k]=true;
        for(int i=0;i<graph.size();++i){
            if(!visited[i] && graph[k][i])dfs(graph, i, visited);
        }
    }
};