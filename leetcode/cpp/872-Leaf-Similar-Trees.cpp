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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        stack<TreeNode*> stk;
        TreeNode *p=root1;
        while(p || !stk.empty()){
            if(p){
                if(p->left==nullptr && p->right==nullptr){
                    t1.push_back(p->val);
                }
                if(p->right)stk.push(p->right);
                p=p->left;
            }else{
                p=stk.top();stk.pop();
            }
        }
        p = root2;
        while(p || !stk.empty()){
            if(p){
                if(p->left==nullptr && p->right==nullptr){
                    t2.push_back(p->val);
                }
                if(p->right)stk.push(p->right);
                p=p->left;
            }else{
                p=stk.top();stk.pop();
            }
        }
        for(int i=0;i<t1.size() && i<t2.size();++i)
            if(t1[i]!=t2[i])return false;
        return t1.size() == t2.size();
    }
};