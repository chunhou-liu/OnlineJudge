#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> reference(numCourses, 0);
        for(auto &p : prerequisites){
            graph[p.second].push_back(p.first);
            ++reference[p.first];
        }
        vector<int> schedule;
        vector<bool> visited(numCourses, false);
        int i = 0;
        while(i<numCourses){
            bool flag = false;
            for(size_t j=0;j<reference.size();++j){
                if(reference[j]==0 && !visited[j]){
                    flag = true;
                    schedule.push_back(j);
                    for(auto k : graph[j])--reference[k];
                    visited[j] = true;
                    ++i;
                }
            }
            if(!flag)break;
        }
        return schedule.size()==numCourses?schedule:vector<int>();
    }
};