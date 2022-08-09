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

int main() {

  Node* head=NULL;
  Node* second=NULL;
  Node* third=NULL;

    head = new Node();
    second = new Node();
    third = new Node();
  
  head->data=5;
  head->next=second;

  second->data=10;
  second->next=third;

  third->data=20;
  third->next=NULL;

  
//insertion of node before front 
 push(&head,100); //as we are using double pointer , we need to pass the address of the head pointer in the function 
  
 display(head);
  

}