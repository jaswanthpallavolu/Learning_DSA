#include<bits/stdc++.h>
using namespace std;

int BinaryIterative(int arr[],int val,int low,int high){

    while(low<=high){
        int mid=(low+high)/2;
        if(val == arr[mid]) return mid;
        else if (val > arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int BinaryRecursive(int arr[],int val,int low,int high){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(val == arr[mid]) return mid;
        else if (val > arr[mid]) BinaryIterative(arr,4,mid+1,high);
        else BinaryIterative(arr,4,low,mid-1);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int N = sizeof(arr)/sizeof(arr[0]);
   
    cout << BinaryIterative(arr,4,0,N-1);
    return 0;
}