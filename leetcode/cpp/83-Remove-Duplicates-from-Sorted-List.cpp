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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;        
        ListNode *it = head;
        while(it->next!=nullptr){
            while(it->next!=nullptr && it->val==it->next->val)it->next=it->next->next;
            if(it->next==nullptr)break;
            it=it->next;
        }
        return head;
    }
};