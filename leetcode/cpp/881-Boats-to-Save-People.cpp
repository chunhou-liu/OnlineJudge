#include <stack>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;

        int end_index = people.size()-1;

        stack<int> stk;
        
        int start_index = 0;
        while(start_index < end_index){
            while(start_index<end_index && people[start_index]+people[end_index]<=limit){
                stk.push(people[start_index]); ++start_index;
            }
            ++count; --end_index;
            if(!stk.empty()){
                stk.pop();
            }
        }
        if(start_index==end_index)stk.push(people[start_index]);
        while(!stk.empty()){
            ++count;
            stk.pop();
            if(!stk.empty())stk.pop();
        }
        return count;
    }
};