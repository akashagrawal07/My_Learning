#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
void swapNode(Node* start, int first,int second)
{
	Node *temp = start;
	Node *A1 = start;
	Node *P1 = start;
	Node *A2 =start;
	Node *P2 = start;
	bool foundFirst = false;
	bool foundSecond = false;
	bool startNodeA1 = false;
	bool startNodeA2 = false;
	while(A1 != NULL && A2!=NULL && !(foundFirst && foundSecond))  
    {  
    	if(A1 == start && A1->data == first)
    	{
    		P1 = A1;
    		foundFirst = true;
		}
		if(A1->next->data == first)
		{
			cout<<"Found First\n";
			foundFirst = true;
			P1 = A1->next;
		    if(A1 == start)
	    	{
	    		startNodeA1 = true;
			}
		}
		if(A2->next->data == second)
		{
			cout<<"Found Second\n";
			foundSecond = true;
			P2 = A2->next;
		    if(A2 == start)
	    	{
	    		startNodeA2 = true;
			}			
		}
		if(!foundFirst)
			A1 = A1->next;
		if(!foundSecond)
			A2 = A2->next;
    }
    cout<<"outsideLoop\n";
    cout<<"A1->"<<A1->data <<endl;
    cout<<"P1->"<<P1->data <<endl;
    cout<<"A2->"<<A2->data <<endl;
    cout<<"P2->"<<P2->data <<endl;    
	A1->next = P2;
	A2->next = P2->next;
	P2->next = P1->next;  
	P1->next = A2->next;
 	A2->next = P1;
//	if(startNodeA1)
//	{
//		start = A1;
//	}
//	if(startNodeA2)
//	{
//		start = A2;
//	}	
    cout<<"A1->"<<A1->data <<endl;
    cout<<"P1->"<<P1->data <<endl;
    cout<<"A2->"<<A2->data <<endl;
    cout<<"P2->"<<P2->data <<endl;    	
	cout<<"A2->next"<<A2->next->data<<endl;
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
