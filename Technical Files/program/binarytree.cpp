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
	
    if(node != NULL)  
    {  
    //	cout<<"Inside print tree\n"<<node;
        cout<<"root--"<<node->data<<endl;  
        if(node->left != NULL)
        	cout<<"Left--"<<node->left->data;  
    	if(node->right != NULL)
    		cout<<"right--"<<node->right->data<<endl;  
    		
		//cout<<endl;
		printTree(node->left);	
		printTree(node->right);
    } 
	cout<<"\n" ;
}  

Node* findEmptyNode(Node* node)
{
	if(node != NULL)
	{
		bool insertLeft = false;
		bool insertright = false;
		if(node->left == NULL || node->right == NULL)
		{
			return node;
		}
		else if(node->left->left == NULL || node->left->right == NULL)
		{
			insertLeft = true;

		}
		else if(node->right->left == NULL || node->right->right == NULL)
		{
			insertright = true;
		}
		cout<<"-------------"<<insertLeft<<insertright<<endl;
		if(insertLeft == true)
			findEmptyNode(node->left);
		else if(insertright == true)
			findEmptyNode(node->right);
			
		if(insertLeft == false && insertright == false)
		{	
			cout<<"enter%%%%%\n";
			findEmptyNode(node);
		}
		
	}
}
void push(Node** head_ref, int new_data) 
{

    Node* new_node =new Node(); 
    
    new_node->data = new_data;  
    new_node->left = NULL;
    new_node->right = NULL;
	
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	Node *node = findEmptyNode(*head_ref);
	if(node->left == NULL)
		node->left = new_node;
	else if(node->right == NULL)
		node->right = new_node;

}    
/* Driver program to test above function */
int main()  
{  
    Node *start = NULL;  
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 10);  
    push(&start, 11);      
    push(&start, 9);    
    push(&start, 7);        
    push(&start, 12);            
    push(&start, 13);                
    push(&start, 14); 
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
/*    push(&start, 2);  
    push(&start, 1);  */
  cout<<"\n print tree\n";
    printTree(start);  
  
  
    return 0;  
}  
