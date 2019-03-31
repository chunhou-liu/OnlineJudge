int LISS(Node *root){
    if(root==nullptr)return 0;
    int liss_left=LISS(root->left), liss_right=LISS(root->right);
    int dp1=liss_left+liss_right, dp2=1;
    if(root->left!=0)dp2+=LISS(root->left->left)+LISS(root->left->right);
    if(root->right!=0)dp2+=LISS(root->right->left)+LISS(root->right->right);
    return max(dp1, dp2);
}