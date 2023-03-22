#include<bits/stdc++.h>
using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int,int> r;
        map<int,int> c;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << i <<"," << j <<"\n";
                if(matrix[i][j]==0){
                    r[i]=1;
                    cout << i;
                }
                if(matrix[i][j]==0){
                    c[j]=1;
                    cout << j;
                }
            }
        }
        
        // for(auto y :r) cout << y.first;
        // for(auto y :c) cout << y.;
        cout << endl;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(r[i]==1 || c[j]==1) matrix[i][j]=0;
            }
    }

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for(auto x:matrix){
        cout << "[";
        for(auto y:x) cout << y << ",";
        cout << "] ";
    }
    return 0;
}