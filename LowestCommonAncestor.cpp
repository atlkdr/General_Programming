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

// Least Common Ancenstor ( traversal )

bool findpath(Node* root,int v,vector<int>& path){
    if(root == NULL) return false;
    path.push_back(root->key);
    if(root->key == v) return true; // Do push before Returning
    if(findpath(root->left,v,path) || findpath(root->right,v,path)){
        return true;
    }else{
        path.pop_back();
        return false;
    }
}


int fLCA(Node* root,int A,int B){
    if(root == NULL) return NULL;
    vector<int> path1; // To A
    vector<int> path2; // To B
    if(findpath(root,A,path1) && findpath(root,B,path2)){
        while(path1.size()>0 && path2.size()>0){
            if(path1[path1.size()-1] == path2[path2.size()-1]){
                break;
            }else{
                path1.pop_back();
                path2.pop_back();
            }
        }
        return path1.size()>0?path1[path1.size()-1]:-1;
    }else{
        return NULL;
    }
}

int main(){
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << fLCA(root, 4, 5)<<endl; 
    cout << "nLCA(4, 6) = " << LCA(root, 4, 6) -> key<<endl; 
    cout << "nLCA(3, 4) = " << LCA(root, 3, 4) -> key<<endl; 
    cout << "nLCA(2, 4) = " << LCA(root, 2, 4) -> key<<endl; 
    return 0;
}
