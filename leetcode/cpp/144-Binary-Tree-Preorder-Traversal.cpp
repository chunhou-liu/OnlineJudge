#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        // No recursion and stack version
        vector<int> res;
        TreeNode *p = root;
        while(p!=nullptr){
            if(p->left!=nullptr){
                TreeNode *tmp = p->left;
                while(tmp->right!=nullptr && tmp->right!=p)tmp=tmp->right;
                if(tmp->right==nullptr){
                    res.push_back(p->val);
                    tmp->right = p;
                    p = p->left;
                }else{
                    tmp->right=nullptr;
                    p = p->right;
                }
            }else{
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};