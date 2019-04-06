#include <vector>
using namespace std;


class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        if(A.size()==0 || A[0].size()==0)return 0;
        int m=A.size(), n=A[0].size();   
        int ans = 0;
        bool flag = false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(A[i][j]==0)continue;
                flag = false;
                int cur = dfs(A, i, j, flag);
                if(!flag)ans += cur;
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> &A, int i, int j, bool &flag){
        if(i<0 || j<0 || i>=A.size() || j>=A[i].size()){
            flag=true;
            return 0;
        }
        if(A[i][j]==0)return 0;
        A[i][j]=0;
        int left = dfs(A, i, j-1, flag),
            right = dfs(A, i, j+1, flag),
            up = dfs(A, i-1, j, flag),
            down = dfs(A, i+1, j, flag);
        return 1 + left + right + up + down;
    }
};