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

// Problem Comes into exsistence when one of left / right is null earler max would have worked fine
int minDepth(Node* root){
    if(root == NULL){
        cout<<"ONLY ONCE"<<endl;
        return 0;
    }
    if(root->left == NULL && root->right == NULL) return 1;
    int left=root->left!=NULL?minDepth(root->left):INT_MAX;
    int right=root->right!=NULL?minDepth(root->right):INT_MAX;
    return 1+min(right,left);
}
// Changing the case check of NULL
int minDepth2(Node* root){
    if(root == NULL){
        return INT_MAX;
    }
    if(root->left == NULL && root->right == NULL) return 1;
    return 1+min(minDepth2(root->left),minDepth2(root->right));
}

int main()
{
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    
    cout <<"The minimum depth of binary tree is : "<< minDepth2(root); 
    return 0; 
    return 0;
}
