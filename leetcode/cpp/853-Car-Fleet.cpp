#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0)return 0;
        map<int, int> car;
        for(int i=0; i<position.size();++i)
            car[position[i]]=speed[i];
        map<int,int>::reverse_iterator map_it = car.rbegin();
        for(int i=0; i<position.size(); ++i, ++map_it){
            position[i]=map_it->first;
            speed[i]=map_it->second;
        }
        vector<float> delta(position.size(), 0);
        for(int i=0;i<position.size();++i)
            delta[i] = float(target-position[i])/speed[i];
        int count = 1;
        for(int i=1;i<position.size();++i){
            if(delta[i]<=delta[i-1]){
                delta[i]=delta[i-1];
            }else{
                ++count;
            }
        }
        return count;
    }
};