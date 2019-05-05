#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // greedy algorithm, choose the activity to be done with max profits everytime
        int max_capital = W;
        priority_queue<int, vector<int>, less<int>> available_profits;
        queue<int> q;
        for(int i=0; i<Capital.size(); ++i){
            if(Capital[i]<=W)available_profits.push(Profits[i]);
            else q.push(i);
        }
        for(int j=0; j<k; ++j){
            if(available_profits.empty())break;
            max_capital += available_profits.top(); available_profits.pop();
            int q_size = q.size();
            for(int i=0; i<q_size; ++i){
                int top = q.front(); q.pop();
                if(Capital[top]<=max_capital){
                    available_profits.push(Profits[top]);
                }else q.push(top);
            }
        }
        return max_capital;
    }
};