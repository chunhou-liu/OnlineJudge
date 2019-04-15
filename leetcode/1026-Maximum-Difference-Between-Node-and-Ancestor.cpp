#include <cmath>
#include <algorithm>
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
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr)return 0;
        int max_diff=0;
        helper(root->left, root->val, root->val, max_diff);
        helper(root->right, root->val, root->val, max_diff);
        return max_diff;
    }
    void helper(TreeNode *root, int max_ans, int min_ans, int &max_diff){
        if(root==nullptr)return;
        int cur_diff = max(abs(max_ans-root->val), abs(min_ans-root->val));
        max_diff = max(max_diff, cur_diff);
        helper(root->left, max(root->val, max_ans), min(min_ans, root->val), max_diff);
        helper(root->right, max(root->val, max_ans), min(min_ans, root->val), max_diff);
    }
};