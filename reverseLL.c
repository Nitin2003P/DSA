#include<stdio.h>
#include<stdlib.h>
    // construct a structure and typedef to node
	typedef struct node{
		int data;
		struct node *next;
        
	}node;
	

//  Create a node 
    node* createNode(int new_data) {
    node *new_node = (node*)malloc(sizeof(node));// Mmory allocate
    if(!new_node){
        printf("Memory is not allocated");
        exit(0);
    }

    new_node->data = new_data;// put data
    new_node->next = NULL; 
    return new_node;
}

	// Print the list
	void print(node *n){
		
		while( n!= NULL){
			printf("%d\n",n->data);
			n=n->next;
		}
	}
	// reverse the list
	node* reverselist(node* head){
        node* arr[10000]; // create a stack
        int top=-1;
        node* x = head;   //  x is a temporary node or dupliacte node
        while(x!=NULL){  
            arr[++top]=x; // array me x ki value daalna hai 
            x = x->next; // x me aage wale vala node ka address

        }  
        if(top>=0){
            head = arr[top];  // ab jo array me top me hoga use head me daal denge
            x = head; // head ko phirse x me daal denge

            while (top>0)
            {
                top--;   //top = top-1
                x->next = arr[top]; // ab jo upar se niche vala hai uska address vala arraay me
                x = x->next; // x me x ka next
            }
            x->next = NULL; //  last x ke null

        }  
        return head; // head ko return 
    }

    
	
	
int main(){


		node *head=createNode(1);
        head->next = createNode(2);
        head->next->next = createNode(3);
        head->next->next->next=createNode(4);
        head->next->next->next->next=createNode(5);


        print(head);

        head=reverselist(head);

        print(head);
        

	}
	