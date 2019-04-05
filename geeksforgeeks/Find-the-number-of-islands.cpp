void dfs(int A[MAX][MAX], int i, int j, int N, int M, vector<vector<bool>> &visited){
    if(i<0 || j<0 || i>=N || j>=M || A[i][j]==0 || visited[i][j])return;
    visited[i][j]=true;
    dfs(A, i+1, j, N, M, visited);
    dfs(A, i-1, j, N, M, visited);
    dfs(A, i, j+1, N, M, visited);
    dfs(A, i, j-1, N, M, visited);
    dfs(A, i-1, j-1, N, M, visited);
    dfs(A, i-1, j+1, N, M, visited);
    dfs(A, i+1, j-1, N, M, visited);
    dfs(A, i+1, j+1, N, M, visited);
}

int findIslands(int A[MAX][MAX], int N, int M){
    int count = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(A[i][j]==0 || visited[i][j])continue;
            dfs(A, i, j, N, M, visited);
            ++count;
        }
    }
    return count;
}