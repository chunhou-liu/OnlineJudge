struct node {
    int data;
   struct node * right, * left;
};
/*You are required to complete this method*/
bool search(node* root, int x)
{
    if(root==nullptr)return false;
    if(root->data==x)return true;
    if(root->data<x)return search(root->right, x);
    return search(root->left, x);
}