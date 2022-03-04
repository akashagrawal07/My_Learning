#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

/* Function to print nodes in a given linked list */
void printList(Node *node)  
{  
    while(node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    } 
	cout<<"\n" ;
}  
void printListReverse(Node *node)  
{  
    if(node != NULL)  
    {
        //.node = node->next;  
		printListReverse(node->next);          
		//if(node != NULL)
		cout<<node->data<<" ";
		
    } 
    
} 
void push(Node** head_ref, int new_data) 
{  
    /* allocate node */
    Node* new_node =new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}    
/* Driver program to test above function */
int main()  
{  
    Node *start = NULL;  
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes() ";  
    printList(start);  

    
  
    cout << "\nLinked list after calling swapNodes() ";  
    printListReverse(start);  
  
    return 0;  
}  
