#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int V;
    list<int>* adj;
    Graph(int V){
        this->V=V;
        this->adj=new list<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        return;
    }
    
    void DFSutil(int start,bool visited[]){
        cout<<start<<" ";
        visited[start]=true;
        for(auto it=adj[start].begin();it!=adj[start].end();it++){
            if(visited[*it] == false){
                DFSutil(*it,visited);
            }
        }
    }
    void DFS(int start){
        bool visited[V];
        for(int i=0;i<V;i++) visited[i]=false;
        DFSutil(start,visited);
    }
};


int main()
{ 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    g.DFS(2);
    return 0; 
} 

