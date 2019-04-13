struct Node{
    int data;
    Node *left,*right;
}; 

int sumOfLeafNodes(Node *r ){
    if(r==nullptr)return 0;
    if(r->left==nullptr && r->right==nullptr)return r->data;
    return sumOfLeafNodes(r->left) + sumOfLeafNodes(r->right);
}