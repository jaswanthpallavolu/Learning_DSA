#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int mid,int r){
    int arr1_n = mid-l+1;
    int arr2_n = r-mid;
    // Create temp arrays
    int i=0,j=0,k;
    int arr1[arr1_n], arr2[arr2_n]; //left, right arrays
    for(i=0;i<arr1_n;i++)
        arr1[i]=arr[l+i];
    for(i=0;i<arr2_n;i++)
        arr2[i]=arr[mid+1+i];

    i=0,j=0,k=l;

    while(i<arr1_n && j<arr2_n){
        if(arr1[i]<=arr2[j]){
            arr[k++]=arr1[i++];
        }else  arr[k++]=arr2[j++];
    }
    while(i<arr1_n) arr[k++]=arr1[i++];
    while(j<arr2_n) arr[k++]=arr2[j++];

    // delete[] arr1;
    // delete[] arr2;
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[]={12,5,2,10,24,13,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(auto x:arr) cout << x <<" ";
    return 0;
}