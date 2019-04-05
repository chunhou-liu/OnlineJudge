#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// when a is true, the b in a && b will not be executed, similarly when a is false in a || b
bool dfs(vector<vector<char>> &chars, int i, int j, queue<pair<int,int>> &q, vector<vector<bool>> &visited){
    if(i<0 || j<0 || i==chars.size() || j==chars[0].size())return false;
    if(chars[i][j]=='X' || visited[i][j])return true;
    visited[i][j]=true;
    q.push(pair<int,int>(i,j));
    bool ans = true;
    ans = dfs(chars, i-1, j, q, visited) && ans;
    ans = dfs(chars, i, j-1, q, visited) && ans;
    ans = dfs(chars, i+1, j, q, visited) && ans;
    ans = dfs(chars, i, j+1, q, visited) && ans;
    return ans;
}

void replaceOwithX(vector<vector<char>> &chars){
    vector<vector<bool>> visited(chars.size(), vector<bool>(chars[0].size(), false));
    queue<pair<int,int>> q;
    for(int i=0;i<chars.size();++i){
        for(int j=0;j<chars[0].size();++j){
            if(chars[i][j]=='X' || visited[i][j])continue;
            if(dfs(chars, i, j, q, visited)){
                while(!q.empty()){
                    pair<int,int> pos=q.front();q.pop();
                    chars[pos.first][pos.second]='X';
                }
            }else{
                while(!q.empty())q.pop();
            }
        }
    }
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int m, n;cin>>m>>n;
        vector<vector<char>> chars(m, vector<char>(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)cin>>chars[i][j];
        replaceOwithX(chars);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cout << chars[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}