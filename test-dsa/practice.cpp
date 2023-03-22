#include<iostream>
using namespace std;

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int mid,int r);


int main(){
    int arr[]={4,8,3,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);


    for(int i=0;i<n;i++){
        cout << arr[i] <<", ";
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1, n2=r-mid;
    int k,i,j;
    int arrL[n1];
    int arrR[n2];
    int sorted_arr[n1+n2];

    for(i=0;i<n1;i++)
        arrL[i]=arr[l+i];
    for(i=0;i<n2;i++)
        arrR[i]=arr[mid+1+i];

    k=l,i=0,j=0;
    while(i<n1 && j<n2){
        if(arrL[i]<arrR[j]) arr[k++]=arrL[i++];
        else arr[k++]=arrR[j++];
    }

    while(i<n1) arr[k++]=arrL[i++];
    while(j<n2) arr[k++]=arrR[j++];

    
}