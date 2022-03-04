#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

/* Function to print nodes in a given linked list */
void printTree(Node *node)  
{  
	cout<<"Inside print tree\n"<<node;
    if(node != NULL)  
    {  
        cout<<node->data<<endl;  
        if(node->left != NULL)
        	cout<<node->left->data << "            ";  
    	if(node->right != NULL)
    		cout<<node->right->data << "            ";  
    	cout<<endl;
		printTree(node->left);	
		printTree(node->right);
    } 
	cout<<"\n" ;
}  

Node* findEmptyNode(Node* head_ref)
{
	if(head_ref != NULL)
	{
		Node * leftNode = findEmptyNode((head_ref)->left);
		Node * rightNode = findEmptyNode(head_ref->right);
	}
}
void push(Node** head_ref, int new_data) 
{
	cout<<"hradref"<<head_ref;
    Node* new_node =new Node(); 
    
    new_node->data = new_data;  
    new_node->left = NULL;
    new_node->right = NULL;
	
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	findEmptyNode(*head_ref);

}    
/* Driver program to test above function */
int main()  
{  
    Node *start = NULL;  
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 7);  
    cout<< start;
/*    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  */
  
    printTree(start);  
  
  
    return 0;  
}  
