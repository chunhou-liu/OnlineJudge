#include <vector>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        for(ListNode *p=head;p!=nullptr;p=p->next){
            ans.push_back(p->val);
            while(!stk.empty()){
                int ind = stk.top();
                if(ans[ind]<p->val){
                    stk.pop();
                    ans[ind]=p->val;
                }else break;
            }
            stk.push(ans.size()-1);
        }
        while(!stk.empty()){
            int ind = stk.top();
            ans[ind]=0;stk.pop();
        }
        return ans;
    }
};