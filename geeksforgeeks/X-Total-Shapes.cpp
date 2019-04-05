#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &arr, int i, int j, vector<vector<bool>> &visited){
    if(i<0 || j<0 || i>=arr.size() || j>=arr[i].size() || visited[i][j] || arr[i][j]!='X')return ;
    visited[i][j] = true;
    dfs(arr, i-1, j, visited);
    dfs(arr, i+1, j, visited);
    dfs(arr, i, j-1, visited);
    dfs(arr, i, j+1, visited);
}

int xTotalShapes(vector<vector<char>> &arr){
    int m=arr.size(), n=arr[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(arr[i][j]=='O' || visited[i][j])continue;
            dfs(arr, i, j, visited);
            ++ans;
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-- > 0){
        int m, n; cin>>m>>n;
        vector<vector<char>> arr(m, vector<char>(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)cin>>arr[i][j];
        cout << xTotalShapes(arr) << endl;
    }
    return 0;
}