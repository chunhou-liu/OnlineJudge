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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
    void dfs(TreeNode *root, int pre, int &total){
        if(root==nullptr)return;
        pre = pre * 10 + root->val;
        if(root->left==nullptr && root->right==nullptr){
            total += pre;
            return;
        }
        dfs(root->left, pre, total);
        dfs(root->right, pre, total);
        return;
    }
};