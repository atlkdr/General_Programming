#include <iostream> 
#include <vector>
using namespace std;

// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Least Common Ancenstor  ( Recursive )

Node* LCA(Node* root,int A,int B){
    if(root == NULL) return NULL;
    if(root->key == A || root->key == B) return root; // A -- B  || B -- A
    Node* left=LCA(root->left,A,B);
    Node* right=LCA(root->right,A,B); // It's like entagled if found A on left then I will surely find B on right
    if(left!=NULL && right!=NULL){
        return root; // Is the LCA
    }else{
        if(left==NULL) return right;
        else return left;
    }
}

// Sorted To binary

Node* sb(int arr[],int l,int r){
    if(l>r) return NULL;
    int mid = ( l + r ) / 2;
    Node* root=newNode(arr[mid]);
    root->left=sb(arr,l,mid-1);
    root->right=sb(arr,mid+1,r);
    return root;
}

void InOrder(Node* node)  
{  
    if (node == NULL)  
        return;  
    InOrder(node->left); 
    cout << node->key <<" ";  
    InOrder(node->right);  
}  

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);
    Node * root = sb(arr, 0, n-1);
    InOrder(root);
    return 0;
}
