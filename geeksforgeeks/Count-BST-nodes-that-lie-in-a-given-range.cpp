/*
The structure of a BST node is as follows:
struct Node
{
    int data;
    Node *left;
    Node *right;
};
*/
int getCountOfNode(Node *root, int l, int h){
    if(root==nullptr)return 0;
    if(root->data>h)return getCountOfNode(root->left, l, h);
    if(root->data<l)return getCountOfNode(root->right, l, h);
    return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
}