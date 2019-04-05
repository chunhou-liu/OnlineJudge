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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *p = root;
        while(p!=nullptr){
            if(p->left!=nullptr){
                TreeNode *tmp = p->left;
                while(tmp->right!=nullptr && tmp->right!=p)tmp=tmp->right;
                if(tmp->right==nullptr){
                    // not visited
                    tmp->right=p;
                    p = p->left;
                }else{
                    tmp->right = nullptr;
                    res.push_back(p->val);
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