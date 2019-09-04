#include <bits/stdc++.h> 
using namespace std; 
  
/* a node of the singly linked list */
class Node  
{  
    public: 
    int data;  
    Node *next;  
}; 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning */
void push(Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
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
    while (node != NULL)  
    {  
        cout << node->data <<" ";  
        node = node->next;  
    }  
}  


void segregateEvenOdd(Node* head){
    Node* even=head;
    Node* odd=head;
    while((even!=NULL)&&(odd!=NULL)){
        // Next even
        while(even!=NULL){
            if((even->data % 2) == 0){
                break;
            }else{
                even=even->next;
            }
        }
        // Next odd
        while(odd!=NULL){
            if((odd->data % 2) != 0){
                break;
            }else{
                odd=odd->next;
            }
        }
        if(even==NULL||odd==NULL) break;
        else{
            // Replace Data
            int temp=even->data;
            even->data=odd->data;
            odd->data=temp;
            
        }
    }
}
  
/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
  
    /* Let us create a sample linked list as following  
    0->2->4->6->8->10->11 */
  
    push(&head, 11); 
    push(&head, 10); 
    push(&head, 9); 
    push(&head, 6); 
    push(&head, 4); 
    push(&head, 1); 
    push(&head, 0); 
  
    cout << "Original Linked list ";  
    printList(head);  
  
    segregateEvenOdd(head);  
  
    cout << "\nModified Linked list ";  
    printList(head);  
  
    return 0;  
}  
