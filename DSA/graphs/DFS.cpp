// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    bool *visited; // make it as global because DFS is recursive
    list<int> *adj; 

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int v);
};
Graph::Graph(int n){
    // this->V = V;
    V=n;
    visited = new bool[V]; //diff with BFS
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

//this function is recursive
void Graph::DFS(int v){
    visited[v] = true;
    cout << v << ' ';

    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i])
            DFS(*i);
    }
}

int main(){
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