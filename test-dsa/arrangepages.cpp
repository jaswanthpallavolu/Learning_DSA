#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> subset;

// void subset1(vector<int> arr,int i);
// void subset2(vector<int> arr,int i);
// void subarray(vector<int> arr,int i,int k);

int main(){
    vector<int> arr = {4,2,1};
    // sort(arr.begin(),arr.end());
    // p1(arr,0);
}

void subarray(vector<int> arr,int i,int k){
    
}

// void subset1(vector<int> arr,int i){
//     if(i==arr.size()){
//         for(auto n:subset)
//             cout << n <<", ";
//         cout << endl;
//         return;
//     }

//     // include
//     subset.push_back(arr[i]);
//     p1(arr,i+1);

//     // not include
//     subset.pop_back();
//     p1(arr,i+1);
// }

//duplicates included
// void subset2(vector<int> arr,int i){
//     if(i==arr.size()){
//         for(auto n:subset)
//             cout << n <<", ";
//         cout << endl;
//         return;
//     }

//     // include
//     subset.push_back(arr[i]);
//     p1(arr,i+1);

//     // not include
//     subset.pop_back();
//     while(i+1<arr.size() && arr[i] ==arr[i+1]) i++;
//     p1(arr,i+1);
// }