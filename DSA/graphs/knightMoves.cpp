#include<bits/stdc++.h>
using namespace std;

struct cell{
    int x,y,dist;
    cell(int x,int y,int dist): 
    x(x),y(y),dist(dist){}
};

bool isValid(int x,int y,int N,vector<vector<bool>> visited){
    if(x>=0 && x<N && y>=0 && y<N && !visited[x][y]) 
        return true;
    return false;
 } 
//Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int> &KnightPos,vector<int> &TargetPos,int N)
	{
	   
        int x=KnightPos[0]-1,y=KnightPos[1]-1;
    
    if(x==TargetPos[0]-1 && y==TargetPos[1]-1){
                        // cout << x <<", "<<y<<endl; 
                        return 0;
                    }
    
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        int dx[]={1,-1,1,-1, 2,2,-2,-2};
        int dy[]={2,2,-2,-2, 1,-1,1,-1};
    
    
        // int minDist=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{x, y},0});
        visited[x][y]=true;
        pair<pair<int,int>,int> currPos;
    
        while(!q.empty()){
                currPos = q.front();
                q.pop();
                
                for(int i=0;i<8;i++){
                    x = currPos.first.first + dx[i];
                    y = currPos.first.second + dy[i];
    
                    if(x==TargetPos[0]-1 && y==TargetPos[1]-1){
                        // cout << x <<", "<<y<<endl; 
                        return currPos.second+1;
                    }
    
                    if(isValid(x,y,N,visited)){
                        q.push({{x,y},currPos.second+1});
                        // cout << x <<", "<<y<<endl;
                        visited[x][y]=true;
                        
                    }
                    
                    
                }
            
            }
        return -1;
    	    
	}


int main(){

    // BFS approach
    // cout << minStepToReachTarget();

    // DP approach
    cout << minStepDP();
    return 0;
}