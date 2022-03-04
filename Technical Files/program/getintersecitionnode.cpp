#include <iostream>
#include<vector>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

/* Function to print nodes in a given linked list */
void printlist(Node *node)  
{  
    while(node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    } 
	cout<<"\n" ;
}  

void getIntersection(Node *head1,Node *head2)
{
	std::vector<Node*> v1;
	std::vector<Node*> v2;
	std::vector<Node*>::iterator it1;
	std::vector<Node*>::iterator it2;	
	Node *temp1 = head1;
	Node *temp2 = head2;
	while( temp1 != NULL || temp2 != NULL)	
	{
        if(temp1 != NULL)
		v1.push_back(temp1);
		if(temp2 != NULL)
		v2.push_back(temp2);

		//it1 = find(v1.begin(),v1.end(),temp2);
		//it2 = std::find(v2.begin(),v2.end(),&*temp1);
		
		if(it1 != v1.end() || it2 != v2.end())
		{
			//cout<<"Same Node-"<<temp1->data<<"  "<<temp2->data<<endl;
			//break;
		}
		if(temp1 != NULL)
		{
		    cout<<"Same Node1-"<<temp1->data<<endl;
		    temp1 = temp1->next;
		}
		if(temp2 != NULL)
		{
		    cout<<"Same Node2-"<<temp2->data<<endl;
		    temp2 = temp2->next;
		}
		
	}
}


int main() 
{ 
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
    printlist(head1);
    printlist(head2);
    getIntersection(head1,head2);
}
