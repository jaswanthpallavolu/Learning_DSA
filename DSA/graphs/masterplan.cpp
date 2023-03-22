#include<bits/stdc++.h>
using namespace std;

bool checkEdge(vector<int,vector<int>> adj,
int v1,int v2){
    if(adj[v1].find(v2)!=-1) return true;
    return false;
}

int main(){
    int N=3,X=0,Y=0,T=2,M=3;
    vector<int,vector<int>> adj;
    
    // add edges
    for(int i=0;i<M;i++){
        int v1,v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    


}