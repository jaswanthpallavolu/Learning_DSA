#include<bits/stdc++.h>
using namespace std;

void kCombinations(vector<vector<int>> &ans,vector<int> &temp,
int index,int i,int n,int k){
    if(index == k){
        ans.push_back(temp);
        return;
    }
    if(i>=n) return;

    temp[index] = i+1;
    kCombinations(ans,temp, index+1,i+1, n,k);
    kCombinations(ans,temp, index,i+1, n,k);
}

void findKCombinations(int n,int k){
    vector<vector<int>> ans;
    vector<int> temp(k,0);
    kCombinations(ans,temp, 0,0, n,k);

    for(auto x:ans){
        for(auto y:x) cout << y <<" ";
        cout <<endl;
    }
}

int main(){
    findKCombinations(5,3);

    
    return 0;
}