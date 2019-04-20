#include <stack>
using namespace std;


class StockSpanner {
    stack<int> spans;
    stack<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!spans.empty() && prices.top()<=price){
            ans += spans.top();
            spans.pop(); prices.pop();
        }
        spans.push(ans);prices.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */