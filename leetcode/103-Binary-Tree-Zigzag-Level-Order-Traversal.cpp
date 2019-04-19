#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return vector<vector<int>>();
        queue<TreeNode*> q;
        queue<int> q_helper;
        q.push(root);
        q_helper.push(0);
        vector<vector<int>> ans;
        while(!q.empty()){
            TreeNode *p = q.front(); q.pop();
            int level = q_helper.front(); q_helper.pop();
            if(level==ans.size())ans.push_back(vector<int>(1, p->val));
            else{
                ans[level].push_back(p->val);
            }
            if(p->left!=nullptr){q.push(p->left);q_helper.push(level+1);}
            if(p->right!=nullptr){q.push(p->right);q_helper.push(level+1);}
        }
        for(int i=0;i<ans.size();++i){
            if(i%2==1){
                // reversed
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};