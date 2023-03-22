#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    if(n<=1) return;

    for(int i=0;i+1<n;i++)
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    bubbleSort(arr,n-1);
}

int main(){
    int arr[]={12,5,2,10,24,13,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(auto x:arr) cout << x <<" ";
    return 0;
}