#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::vector<int> v={1, 13, 6, 8, 9, 3, 5};
    // std::vector<vector<int>> ans;
    // int k=4;
    // std::map<int,vector<int>> m;

    // sort(v.begin(),v.end());

    // int start=0;
    // for(int i=0;i<v.size();i++){
    //     if(v[i]-v[start]<=k)
    //         m[start].push_back(v[i]);
    //     else start=i--;
    // }

    // for(auto s:m){
    //     for(auto e:s.second){
    //         cout << e <<",";
    //     }
    //     cout << endl;
    // }

    vector<int> arr ={10,4,8,13,20};
    int m=2,n=arr.size(),lg=0;
    int total=0;

    for(int i=0;i+m-1<n;i++){
        int sum=0;
        int j=i;
        int count=m;
        while(count--)
            sum+=arr[j++]; 
        if(sum > lg) lg=sum;
    }
    
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    cout << "o/p: "<<total-lg;
    return 0;
}