#include <bits/stdc++.h> 
#include <algorithm>

using namespace std; 


class node { 
public: 
    int data; 
    node* left; 
    node* right; 
}; 
  
int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
}   

int isBalanced(node* root){
    if(root==NULL) return 0;
    int left_height=isBalanced(root->left);
    int right_height=isBalanced(root->right);
    if( left_height*right_height < 0 ){
        // One Has returned -1 Meaning not balanced
        return -1;
    }else{
        if(abs(left_height-right_height)<=1){
            // balanced Hence return It's heoght
            return 1+max(left_height,right_height);
        }else{
            return -1; // Left And Right Were Balanced but not this one 
        }
    }
} 

int h(node* root){
    if(root == NULL) return 0;
    else{
        return 1+max(h(root->left),h(root->right));
    }
}

node* newNode(int data) 
{ 
    node* Node = new node(); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
  
    return (Node); 
} 



int main() 
{ 
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(8); 
    int height=isBalanced(root);
    if (height!=-1) 
        cout << "Tree is balanced "<<height<<" Cal: "<<h(root)<<endl; 
    else
        cout << "Tree is not balanced"; 
    return 0; 
} 
