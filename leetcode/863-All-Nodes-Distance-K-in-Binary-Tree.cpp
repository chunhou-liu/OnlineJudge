#include <vector>
#include <stack>
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
    enum Branch {LEFT, RIGHT, BOTH};
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        stack<TreeNode*> stk;
        TreeNode *p = root, *q=nullptr;
        while(p || !stk.empty()){
            if(p){
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                if(p->right!=nullptr && q!=p->right)p=p->right;
                else{
                    //visit p
                    if(p==target)break;
                    stk.pop();
                    q=p;
                    p=nullptr;
                }
            }
        }
        vector<int> res;
        p = stk.top();
        stk.pop();
        helper(p, K, BOTH, res);
        int k = K - 1;
        while(!stk.empty()){
            if(stk.top()->left==p){
                helper(stk.top(), k, RIGHT, res);
            }else{
                helper(stk.top(), k, LEFT, res);
            }
            k -= 1;
            p = stk.top();
            stk.pop();
        }
        return res;
    }
    void helper(TreeNode *root, int K, Branch branch, vector<int> &res){
        if(root==nullptr)return;
        if(K<0)return;
        if(K==0){res.push_back(root->val);return;}
        else{
            switch(branch){
                case LEFT:
                    helper(root->left, K-1, BOTH, res);
                    break;
                case RIGHT:
                    helper(root->right, K-1, BOTH, res);
                    break;
                case BOTH:
                    helper(root->left, K-1, branch, res);
                    helper(root->right, K-1, branch, res);
                    break;
            }
        }
    }
};