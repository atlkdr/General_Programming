#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int key; 
    struct Node* next; 
}; 
  
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print a linked list 
void printList(Node* head) 
{ 
    while (head != NULL) { 
        cout << head->key << " "; 
        head = head->next; 
    } 
    cout << endl; 
} 

bool detectLoop(Node* start){
    if(start == NULL || start->next == NULL) return false;
    else{
        Node* slow=start;
        Node* fast=start->next->next;
        bool loop=false;
        Node* meetpoint;
        while(fast!=NULL && slow!=NULL){
            if(fast->key == slow->key){
                loop=true;
                break;
            }else{
                if(fast->next == NULL) break;
                meetpoint=fast;
                fast=fast->next->next;
                slow=slow->next;
            }
        }
         // Main Point to be noted Here (m+k)
        if(loop == true){
            slow=start;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
        return loop;
    }
}

void traverse(Node* root){
    while(root!=NULL){
        cout<<root->key<<" ";
        root=root->next;
    }cout<<"\n";
}

int main() 
{ 
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
  
    /* Create a loop for testing(5 is pointing to 3) */
    head->next->next->next->next->next = head->next->next->next; 
  
    bool found = detectLoop(head); 
    if (found) 
        cout << "Loop Found"<<endl; 
    else
        cout << "No Loop"<<endl; 
    found = detectLoop(head); 
    if (found) 
        cout << "Loop Found"<<endl; 
    else
        cout << "No Loop"<<endl;
        traverse(head);
  
    return 0; 
} 
