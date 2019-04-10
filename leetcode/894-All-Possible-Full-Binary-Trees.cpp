#include <vector>
#include <map>
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
    map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N==1)return vector<TreeNode*>(1, new TreeNode(0));
        if(N==2)return vector<TreeNode*>();
        if(memo.find(N)!=memo.end())return memo[N];
        vector<TreeNode*> res;
        for(int left=1;left<N-1;left+=2){
            vector<TreeNode*> left_subtree = allPossibleFBT(left),
                              right_subtree = allPossibleFBT(N-1-left);
            for(int i=0;i<left_subtree.size();++i){
                for(int j=0;j<right_subtree.size();++j){
                    TreeNode *root = new TreeNode(0);
                    root->left = left_subtree[i];
                    root->right = right_subtree[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};