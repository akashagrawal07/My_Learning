#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
void swapNode(Node* start, int first,int second)
{
	Node *firstNode = start;
	Node *secondNode = start;
	bool foundFirst = false;
	bool foundSecond = false;
	while(firstNode != NULL && secondNode != NULL && (!foundFirst || !foundSecond))
	{
		if(firstNode->data == first)
		{
			foundFirst = true;
		}
		if(!foundFirst)
		{
			firstNode = firstNode->next;
		}
		
		
		if(secondNode->data == second)
		{
			foundSecond = true;
		}
		if(!foundSecond)
		secondNode = secondNode->next;
	}
	cout<<"First->"<<firstNode->data<<endl;
	cout<<"Second->"<<secondNode->data<<endl;
	Node *tmpNode = start;
	tmpNode = firstNode;
	firstNode = secondNode;
	secondNode = tmpNode;
	cout<<"Swap Node Exit\n";
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
	swapNode(start,1,7);
    
  
    cout << "\nLinked list after calling swapNodes() ";  
    printList(start);  
  
    return 0;  
}  
