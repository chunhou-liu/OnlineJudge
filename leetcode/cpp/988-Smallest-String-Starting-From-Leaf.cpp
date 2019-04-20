#include <string>
#include <vector>
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
    string smallestFromLeaf(TreeNode* root) {
        string path, best;
        dfs(root, path, best);
        return best;
    }
    void dfs(TreeNode *root, string &path, string &best){
        if(root==nullptr)return;
        path.push_back('a'+root->val);
        if(root->left==nullptr && root->right==nullptr){
            string cur(path.rbegin(), path.rend());
            if(best=="" || cur<best)best=cur;
        }
        dfs(root->left, path, best);
        dfs(root->right, path, best);
        path.pop_back();
    }
};