#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size()==0)return 0;
        vector<bool> visited(M.size(), false);
        int count = 0;
        for(int i=0;i<visited.size();++i){
            if(!visited[i]){
                dfs(M, i, visited);
                ++count;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &A, int k, vector<bool> &visited){
        visited[k] = true;
        for(int i=0;i<A[k].size();++i){
            if(!visited[i] && A[k][i]==1)dfs(A, i, visited);
        }
    }
};