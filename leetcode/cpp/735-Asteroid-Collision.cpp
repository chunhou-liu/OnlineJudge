#include <vector>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto aster : asteroids){
            if(aster>0)ans.push_back(aster); // move
            else{
                while(!ans.empty() && ans.back()>0 && ans.back() < -aster)ans.pop_back();
                if(!ans.empty() && ans.back()>0 && ans.back()==-aster)ans.pop_back();
                // aster can live if ans.back() < 0 || ans.empty();
                else if(ans.empty() || ans.back()<0)ans.push_back(aster);
            }
        }
        return ans;
    }
};