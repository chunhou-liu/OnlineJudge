#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    bool isValidBST(TreeNode* root) {
        // in-order traverse will get an increasing array
        vector<TreeNode*> inorder;
        stack<TreeNode*> stk;
        TreeNode *p=root;
        while(p || !stk.empty()){
            if(p){
                stk.push(p);
                p=p->left;
            }else{
                p=stk.top();stk.pop();
                inorder.push_back(p);
                p=p->right;
            }
        }
        for(int i=1;i<inorder.size();++i)
            if(inorder[i]->val<=inorder[i-1]->val)return false;
        return true;
    }
};