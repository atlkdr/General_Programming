#include <bits/stdc++.h>
#include <stack>
#include <map>
using namespace std; 
  
void nextGreat(int arr[],int N){
    stack<int> s;
    map<int,int> mp; // Array Element, Greater Element
    for(int i=0;i<N;i++){
        if(!s.empty()){
            while(!s.empty() && arr[i]>s.top()){
                mp[s.top()]=arr[i];
                s.pop();
            }
        }
        mp[arr[i]]=-1;
        s.push(arr[i]);
    }
    for(int i=0;i<N;i++){
        cout<<mp[arr[i]]<<" ";
    }cout<<'\n';
}

int main(){ 
    int arr[] = {11, 13, 21, 3}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  nextGreat(arr, n); 
    return 0; 
} 
