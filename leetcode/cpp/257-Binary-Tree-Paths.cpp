#include <cstdlib>
#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        dfs(root, path, ans);
        return ans;
    }
    void dfs(TreeNode *root, vector<int> &path, vector<string> &rootToleafPaths){
        if(root==nullptr)return;
        if(root->left==nullptr && root->right==nullptr){
            // leaf node
            path.push_back(root->val);
            string tmp = to_string(path[0]);
            for(int i=1;i<path.size();++i){
                tmp += "->";
                tmp += to_string(path[i]);
            }
            rootToleafPaths.push_back(tmp);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, path, rootToleafPaths);
        dfs(root->right, path, rootToleafPaths);
        path.pop_back();
    }
};