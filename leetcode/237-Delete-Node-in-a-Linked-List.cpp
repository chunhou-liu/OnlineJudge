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
    void deleteNode(ListNode* node) {
        if(node==nullptr)return;
        while(node->next!=nullptr){
            node->val=node->next->val;
            if(node->next->next!=nullptr)node = node->next;
            else break;
        }
        node->next=nullptr;
    }
};