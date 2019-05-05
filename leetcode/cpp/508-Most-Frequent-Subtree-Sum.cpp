#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freq_map;
        int max_freq=0;
        helper(root, freq_map, max_freq);
        vector<int> ans;
        for(unordered_map<int,int>::iterator i=freq_map.begin(); i!=freq_map.end(); ++i){
            if(i->second==max_freq)ans.push_back(i->first);
        }
        return ans;
    }
    int helper(TreeNode *root, unordered_map<int,int> &map, int &ans_freq){
        if(root==nullptr)return 0;
        int left = helper(root->left, map, ans_freq),
            right = helper(root->right, map, ans_freq);
        int cur = root->val + left + right;
        if(map.find(cur)!=map.end()){
            ++map[cur];
        }
        else{
            map[cur]=1;
        }
        ans_freq = max(ans_freq, map[cur]);
        return cur;
    }
};