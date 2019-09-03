#include <bits/stdc++.h> 
#include <algorithm>

using namespace std; 

struct tnode{
    int key;
    tnode* arr[26];     
};

tnode* newNode(){
    tnode* newnode=new tnode;
    newnode->key=-1;
    for(int i=0;i<26;i++){
        newnode->arr[i]=NULL;
    }
    return newnode;
}

void util(tnode* root,vector<char> c,int val){
    if(c.size()==0){
        root->key=val;
        return;
    }
    char x=c[c.size()-1];
    c.pop_back();
    if(root->arr[x-'a'] == NULL) root->arr[x-'a']=newNode();
    util(root->arr[x-'a'],c,val);
}

tnode* insert(tnode* root,string s,int val){
    vector<char> c;
    for(int i=s.size()-1;i>=0;i--){
        c.push_back(s[i]);
    }
    if(root==NULL) root=newNode();
    util(root,c,val);
    return root;
}

void util2(tnode* root,string s){
    if(root == NULL) return;
    if(root->key!=-1){
        cout<<s<<" "<<root->key<<endl;
    }
    for(int i=0;i<26;i++){
        if(root->arr[i]!=NULL){
            int x=i+'a';
            s+=(char)x;
            util2(root->arr[i],s);
        }
    }
}

void traverse(tnode* root){
    if(root == NULL) return;
    util2(root,"");
}

int search(tnode* root,string x){
    
    if(x=="" && root->key!=-1) return root->key;
    if(x=="") return -1;
    char c=x[0];
    string s=x.substr(1,x.size()-1);
    if(root->arr[c-'a']!=NULL) return search(root->arr[c-'a'],s);
    return -1;
}

int main() 
{ 
    tnode*  newnode=insert(NULL,"car",10);
    insert(newnode,"carry",100);
    traverse(newnode);
    cout<<search(newnode,"carry")<<endl;
    return 0; 
}
