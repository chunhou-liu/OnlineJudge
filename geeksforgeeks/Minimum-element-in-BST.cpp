struct node {
	int data;
	node* left;
	node* right;
};

// your task is to complete the below function
int minValue(struct node* root){
    if(root==nullptr)return -1;
    node *p = root;
    while(p->left!=nullptr)p=p->left;
    return p->data;
}