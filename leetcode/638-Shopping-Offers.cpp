#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, special.size()-1, needs);
    }
    int dfs(vector<int> &price, vector<vector<int>> &special, int k, vector<int> &needs){
        if(k<0){
            int pay = 0;
            for(int i=0;i<needs.size();++i)pay+=price[i]*needs[i];
            return pay;
        }
        if(check_offer(special[k], needs)){
            int pay = dfs(price, special, k-1, needs);
            for(int i=0;i<needs.size();++i){
                needs[i] -= special[k][i];
            }
            pay = min(pay, special[k][special[k].size()-1]+dfs(price, special, k, needs));
            for(int i=0;i<needs.size();++i){
                needs[i] += special[k][i];
            }
            return pay;
        }else{
            return dfs(price, special, k-1, needs);
        }
    }
    bool check_offer(vector<int> &offer, vector<int> &need){
        for(int i=0;i<need.size();++i)
            if(offer[i]>need[i])return false;
        return true;
    }
};