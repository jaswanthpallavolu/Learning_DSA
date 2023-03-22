#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> m,int n,int x,int y){
    if(x>=0 && x<n && y>=0 && y<n&&m[x][y]) return true;
    return false;
}
void printSol(vector<vector<int>> sol){
    for(auto x:sol){
        for(auto y:x)
            cout<<y << ", ";
        cout <<endl;
    }
}



bool solveMazeUtil(vector<vector<int>> m,
int n,int x,int y,vector<vector<int>> &sol){
    if(x==n-1 && y==n-1 && m[x][y]){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(m,n,x,y)){
        if(sol[x][y]) return false;

        sol[x][y]=1;
        if(solveMazeUtil(m,n,x+1,y,sol)) return true;
        if(solveMazeUtil(m,n,x,y+1,sol)) return true;
        sol[x][y]=0;
        return false;
    }
    return false;
}

void solveMaze(vector<vector<int>> m, int n) {
    vector<vector<int>> sol(n, vector<int>(n,0));
    if(!solveMazeUtil(m,n,0,0,sol)){
        cout<<"Solution doesn't exist";
    }
    printSol(sol);
    
}

// vector<string> findPath(vector<vector<int>> &m, int n) {
//     vector<vector<int>> sol(n, vector<int>(n,0));
// }

int main(){
    vector<vector<int>> m={ { 1, 0, 0, 0 },
                            { 1, 1, 0, 1 },
                            { 0, 1, 0, 0 },
                            { 1, 1, 1, 1 } };
    int n=m.size();
    solveMaze(m,n);
    return 0;
}