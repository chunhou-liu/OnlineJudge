#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size()==0)return true;
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(int i=0;i<visited.size();++i)
            if(!visited[i])return false;
        return true;
    }
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int k){
        visited[k]=true;
        for(int i=0;i<rooms[k].size();++i){
            if(!visited[rooms[k][i]])dfs(rooms, visited, rooms[k][i]);
        }
    }
};