struct Node
{
    int data;
    Node* left;
    Node* right;
};
/* Should convert tree to its mirror */
void mirror(Node* node) {
    if(node==nullptr)return;
    Node* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    mirror(node->left);
    mirror(node->right);
}