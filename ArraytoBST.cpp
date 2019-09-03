#include<bits/stdc++.h> 
using namespace std;
// In case of: ( 0 , n-1 ) if n is odd:- mid is chosen else mid - 1 th element is chosen   
  
/* A Binary Tree node */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  

node* newNode(int data)  
{  
    node* n = new node(); 
    n->data = data;  
    n->left = NULL;  
    n->right = NULL;  
  
    return n;  
}  

void preOrder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}
node* sortedArray(int arr[],int start,int end){
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    node* temp=newNode(arr[mid]);
    temp->left=sortedArray(arr,start,mid-1);
    temp->right=sortedArray(arr,mid+1,end);
    return temp;
}

int main()  
{  
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);
    node *root = sortedArray(arr, 0, n-1);  
    cout << "PreOrder Traversal of constructed BST \n";  
    preOrder(root);  
  
    return 0;  
}  
  


