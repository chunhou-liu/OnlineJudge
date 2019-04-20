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
    vector<int> postorderTraversal(TreeNode* root) {
        // LRN traversal is the reverse of NRL traversal
        vector<int> res;
        TreeNode *p = root;
        while(p!=nullptr){
            if(p->right!=nullptr){
                TreeNode *tmp = p->right;
                while(tmp->left!=nullptr && tmp->left!=p)tmp=tmp->left;
                if(tmp->left==nullptr){
                    res.push_back(p->val);
                    tmp->left = p;
                    p = p->right;
                }else{
                    tmp->left = nullptr;
                    p = p->left;
                }
            }else{
                res.push_back(p->val);
                p = p -> left;
            }
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};