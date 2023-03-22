
#include<bits/stdc++.h>
using namespace std;


bool solve(vector<vector<char>>& board,int i,int j,string word,int k,vector<vector<bool>>& vis){
        int m=board.size();
        int n=board[0].size();
        int h = word.size();
        if(k>h-1) return true;
        if(i<0 || i>m-1 || j<0 || j>n-1) return false;
        if(vis[i][j] || board[i][j]!=word[k]) return false;
        vis[i][j]=true;
        cout << "(" <<i<<","<<j <<endl;
        cout << word[k] <<" - " <<board[i][j];
        if(solve(board,i,j-1,word,k+1,vis)||
        solve(board,i,j+1,word,k+1,vis)||
        solve(board,i+1,j,word,k+1,vis)||
        solve(board,i-1,j,word,k+1,vis))
        return true;

        return false;
    }
bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout << word[0] <<" - " <<board[i][j] <<", ";
                if(board[i][j]==word[0]){
                    cout << "in fnc, ";
                    vector<vector<bool>> vis(m,vector<bool>(n,false));
                    if(solve(board,i,j,word,0,vis))
                        return true;

                }
            }
        }
        return false;
    }
int main(){
    vector<vector<char>> board= {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
string word="ABCCED";
 cout << exist(board,word);

    return 0;
}