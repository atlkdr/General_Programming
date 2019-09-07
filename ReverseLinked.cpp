#include <iostream>

using namespace std;

typedef struct node{
    int val;
    node* next;
}node;

void traverse(node* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->next;
    }
    cout<<"\n";
    return;
}

void add(node** root,int val){
    node* head=*root;
    node* temp=new node;
    temp->val=val;
    temp->next=head;
    *root=temp;
    return;
}

void reverse(node** root){
    node* head=*root;
    node* prev=NULL;
    node* next;
    node* curr=head;
    while(next!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *root=prev;
}


int main()
{
    node* root;
    add(&root,4);
    add(&root,7);
    add(&root,10);
    traverse(root);
    reverse(&root);
    traverse(root);
    return 0;
}
