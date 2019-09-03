#include<bits/stdc++.h> 
using namespace std; 
  
// A BT Node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
};

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 

int minDepth(Node* root){
    if(root == NULL) return 0;
    return 1+min(minDepth(root->left),minDepth(root->right));
}

int main()
{
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    cout <<"The minimum depth of binary tree is : "<< minDepth(root); 
    return 0; 
    return 0;
}
