#include<iostream> 
#include <list> 
#include <stack> 

using namespace std;

class Graph{
    public:
        int V;
        list<int>* adj;
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        return;
    }
    void util(int i,bool visited[],stack<int>& s){
        visited[i]=true;
        for(auto it=adj[i].begin();it!=adj[i].end();it++){
            if(visited[*it] == false){
                util(*it,visited,s);
            }
        }
        s.push(i);
    }
    void toposort(){
        bool visited[V];
        for(int i=0;i<V;i++) visited[i]=false;
        stack<int> s;
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                util(i,visited,s);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<endl;
            s.pop();
        }
    }
};

int main(){
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    g.toposort();
    return 0;
}

