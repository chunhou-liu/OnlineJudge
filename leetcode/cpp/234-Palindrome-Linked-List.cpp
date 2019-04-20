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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return true;
        int length = 0;
        for(ListNode *p=head;p!=nullptr;p=p->next)++length;
        ListNode *p = head->next;head->next=nullptr;
        for(int i=1;i<length/2;++i){
            ListNode *tmp = p->next;
            p->next = head;
            head = p;
            p = tmp;
        }
        if(length%2==1)p=p->next;
        for(ListNode *q=head, *r=p;q!=nullptr && r!=nullptr;q=q->next,r=r->next)
            if(q->val!=r->val)return false;
        
        return true;
    }
};