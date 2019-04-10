#include <vector>
using namespace std;

class RecentCounter {
    vector<int> pings;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int count = 0;
        for(int i=pings.size()-1;i>=0;--i){
            if(t-pings[i]<=3000)++count;
        }
        pings.push_back(t);
        return count+1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */