struct Node
{
    int data;
    Node* next;
};
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node){
   Node *prev = nullptr;
   while(node->next!=nullptr){
       node->data = node->next->data;
       prev = node;
       node = node->next;
   }
   delete prev->next;
   prev->next=nullptr;
}