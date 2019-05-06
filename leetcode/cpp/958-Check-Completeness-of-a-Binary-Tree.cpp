#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr)return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur==nullptr)break;
            q.push(cur->left);
            q.push(cur->right);
        }
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur!=nullptr)return false;
        }
        return true;
    }
};