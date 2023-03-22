#include <bits/stdc++.h>
using namespace std;

void partitionAlgo(int arr[],int low,int high);


int main(){
    int arr[] = {30,80,10,90,50,40,70};
    int n=sizeof(arr)/sizeof(arr[0]);
    partitionAlgo(arr,0,n-1);
    return 0;
}
void partitionAlgo(int arr[],int low,int high){

    int pivot=(low+high)/2+1;
    //for smaller element index and left to the pivot element
    int i=low-1; 

    for(int j=low;j<=high;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[pivot]);

    for(int k=low;k<=high;k++)
        cout << arr[k]<<", ";
}