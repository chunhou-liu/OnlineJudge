#include <vector>
#include <map>
#include <cmath>
using namespace std;


class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        map<int, vector<vector<int>>> dis_point_map;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                int distance = abs(i-r0) + abs(j-c0);
                vector<int> cur(2);cur[0]=i;cur[1]=j;
                if(dis_point_map.find(distance)==dis_point_map.end()){
                    dis_point_map[distance]=vector<vector<int>>();
                }
                dis_point_map[distance].push_back(cur);
            }
        }
        vector<vector<int>> ans;
        for(map<int, vector<vector<int>>>::iterator i=dis_point_map.begin(); i!=dis_point_map.end(); ++i){
            ans.insert(ans.end(), i->second.begin(), i->second.end());
        }
        return ans;
    }
};