#include <iostream>
using namespace std;

class Node{
public:
 int data;
 Node* next;
};

//funtion to display the the linked list 
void display(Node* head){
   while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
}


// funtion to insert the node at front 
void push(Node ** head_ref, int value){
  Node* new_node = new Node(); // allocating the new node
  new_node->data=value;// storing the value to the new node
  
  new_node->next= (*head_ref);// pointing the next pointer to current head 
  (*head_ref)=new_node;//making new node as head
  
  
}

//function to insert the node after some node
void insertafter(Node *prev_node, int value){

  Node * new_node= new Node();
  if(prev_node==NULL){
    cout<<"Previous node is NULL"<<endl;
  }
  new_node->data=value;
  new_node->next=prev_node->next;
  prev_node->next=new_node;
}

//function to insert the node at end
void insert_last(Node **head_ref, int value){
  
  Node *new_node = new Node();  // allocate the node
  Node *last_node= *head_ref;   //make a new node have ref to head node
  
  new_node->data=value; 
  new_node->next=NULL;

  //check if the list is empty or not
  if((*head_ref)== NULL){
    *head_ref = new_node; // if empty create the new node
  }
    //else traverse the list till the last node 
  else{
    while(last_node->next!=NULL){
      last_node=last_node->next;  //update the next of the last node
    }
  }

  last_node->next=new_node; //make the last node pointing to the new node we created
  
  
}

void delete_front(Node** head_ref){
  Node* temp= new Node();
  temp= *head_ref;         //copying the head to a temp node
  *head_ref=temp->next;    //point the head to the next head
  free(temp);              // free the memory used -> we can use 'delete' also 
  return;
  
}

//function to delete last node 
void delete_last(Node* head_ref){

  Node* temp =head_ref;
  Node* prev_node = NULL;  // pointer to maintain 
  while(temp->next != NULL){
   prev_node=temp;
   temp=temp->next;
 }
  if(temp== head_ref){
    head_ref=NULL;
  }else{
    prev_node->next=NULL;
    free(temp);
  }
}

//function to delete a node
void delete_node(Node* head_ref,int count){
  int i =1; 
  Node* next_node= new Node();
  Node* prev= head_ref;

  while (i<count-1){    //loop will run till count -1 so that we can access the next                               element
    prev=prev->next;
    i++;
  
  }
  next_node= prev->next; 
    prev->next=next_node->next;
  free(next_node);
}

//main function 
int main() {

  Node* head=NULL;
  Node* second=NULL;
  Node* third=NULL;
  
// Allocate the new nodes
    head = new Node();
    second = new Node();
    third = new Node();
  
  head->data=5;             //inserting the value
  head->next=second;        //pointing the next pointer to the next node

  second->data=10;
  second->next=third;

  third->data=20;
  third->next=NULL;

  
//insertion of node before front 
 push(&head,100);                   //as we are using double pointer , we need to pass the address                                       of the head pointer in the function 
                                   // time complexity is O(1)
  
//insertion of node after a node 
 insertafter(second, 200);        // first arg is the node we want to add the node after , second                                       is the value
                                  // time complexity is O(n)
  
//insertion of a node at last
  insert_last(&head, 1000);

 // display(head);
cout<<endl;
  
//deletion of first element 
  
  delete_front(&head);

//deletion of last element
  
  delete_last(head);

//deletion of an element
 display(head);
 delete_node(head, 2);
cout<<endl;

  
//fucntion to display the linked list
 display(head);
  

}