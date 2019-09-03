#include <bits/stdc++.h> 
#include <algorithm>

using namespace std; 

struct node{
    int data;
    node* left,*right;
};

node* newNode(int val){
    node* temp=new node;
    temp->data=val;
    temp->right=temp->left=NULL;
    return temp;
}

void serialize(node* root,vector<int>& v){
    if(root == NULL) return;
    v.push_back(root->data);
    serialize(root->left,v);
    serialize(root->right,v);
    return;
}

int findIndex(vector<int> v,int val,int start,int end){
    for(int i=start;i<=end;i++){
        if(v[i]>val) return i;
    }
    return -1;
}

node* deserialize(vector<int> v,int low,int high){
    if(low>high) return NULL;
    node* temp=newNode(v[low]);
    int split=findIndex(v,v[low],low+1,high);
    if(split == -1){ // no split val = no right subtree
        split=high+1;
    }
    temp->left=deserialize(v,low+1,split-1);
    temp->right=deserialize(v,split,high);
    return temp;
}
void traverse(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    traverse(root->left);
    traverse(root->right);
    return;
}
int main() 
{ 
    node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14);
    vector<int> v({10, 5, 1, 7, 40, 50});
    node* temp=deserialize(v,0,v.size()-1);
    traverse(temp);
    return 0; 
}
