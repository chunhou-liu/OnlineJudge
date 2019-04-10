#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        vector<long long> left(n, INT_MAX);
        vector<long long> right(n, INT_MAX);
        vector<long long> min_radius(n, INT_MAX);
        long long int res = 0;
        for(int i=0, j=0;i<n;++i){
            int k = j;
            for(k=j;k<heaters.size() && heaters[k]<houses[i];++k)left[i]=heaters[k];
            if(k<heaters.size())right[i] = heaters[k];
            else right[i] = heaters.back();
            if(right[i]<=houses[i])j=min(k, int(heaters.size())-1);
            min_radius[i] = min(abs(left[i]-houses[i]), abs(right[i]-houses[i]));
            res = max(res, min_radius[i]);
        }
        return res;
    }
};