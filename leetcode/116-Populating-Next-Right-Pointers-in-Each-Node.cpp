#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> p;
        dfs(root, p, 0);
        for(int i=0;i<p.size();++i)
            p[i]->next=nullptr;
        return root;
    }
    void dfs(Node *root, vector<Node*> &p, int h){
        if(root==nullptr)return;
        if(h==p.size()){
            p.push_back(root);
        }else{
            p[h]->next = root;
            p[h] = root;
        }
        dfs(root->left, p, h+1);
        dfs(root->right, p, h+1);
    }
};