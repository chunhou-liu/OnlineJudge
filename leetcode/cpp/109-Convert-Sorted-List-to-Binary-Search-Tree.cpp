#include <cstdlib>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode *p = head;
        int count = 1;
        while(p->next!=nullptr){
            p=p->next;++count;
        }
        return buildTree(head, p, count);
    }
    TreeNode* buildTree(ListNode *head, ListNode *tail, int count){
        if(count<=0)return nullptr;
        if(count==1)return new TreeNode(head->val);
        ListNode *p = head, *prev=p;
        for(int i=0; i<count/2;++i){prev=p;p=p->next;}
        TreeNode *root = new TreeNode(p->val);
        root->left = buildTree(head, prev, count/2);
        root->right = buildTree(p->next, tail, count-count/2-1);
        return root;
    }
};