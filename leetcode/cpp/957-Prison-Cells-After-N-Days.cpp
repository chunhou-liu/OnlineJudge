#include <vector>
using namespace std;

class Solution {
    struct ListNode{
        vector<int> state;
        ListNode * next;
        ListNode(vector<int> s, ListNode *_next=nullptr): state(s), next(_next) {}
    };
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<ListNode*> states;
        bool has_loop = false;
        int loop_start_index = -1;
        states.push_back(new ListNode(cells, nullptr));
        ListNode *prev = states[0];
        while(!has_loop && states.size()<=N){
            vector<int> new_state(prev->state);
            new_state[0]=new_state[7]=0;
            for(int j=1; j<7; ++j)
                if(prev->state[j-1]==prev->state[j+1])new_state[j]=1;
                else new_state[j]=0;
            for(int i=0; i<states.size();++i){
                if(vector_cmp(states[i]->state, new_state)){
                    prev->next = states[i];
                    loop_start_index = i;
                    has_loop = true;
                    break;
                }
            }
            if(!has_loop){
                prev->next = new ListNode(new_state, nullptr);
                states.push_back(prev->next);
                prev = prev->next;
            }
        }
        if(!has_loop){
            return states.back()->state;
        }
        int loop_size = states.size() - loop_start_index;
        N = (N-loop_start_index) % loop_size;
        ListNode *p = states[loop_start_index];
        for(int i=0; i<N; ++i){
            p = p->next;
        }
        vector<int> ans = p->state;
        for(auto i : states)delete i;
        return ans;
    }
    bool vector_cmp(vector<int> &a, vector<int> &b){
        for(int i=0; i<a.size();++i)
            if(a[i]!=b[i])return false;
        return true;
    }
};