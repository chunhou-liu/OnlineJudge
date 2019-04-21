#include <climits>
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
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr)return INT_MAX;
        int ans = INT_MAX;
        ans = min(ans, getMinimumDifference(root->left));
        ans = min(ans, getMinimumDifference(root->right));
        // most right in left
        TreeNode *p1 = root->left, *p2 = root->right;
        while(p1!=nullptr && p1->right!=nullptr)p1=p1->right;
        while(p2!=nullptr && p2->left!=nullptr)p2=p2->left;
        if(p1!=nullptr)ans = min(ans, root->val-p1->val);
        if(p2!=nullptr)ans = min(ans, p2->val-root->val);
        return ans;
    }
};