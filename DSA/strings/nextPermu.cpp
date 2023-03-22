#include <iostream>
using namespace std;

void printArr(int arr[],int N){
    for(int i=0;i<N;i++)
        cout << arr[i] << ',';
}

int main(){
    // int arr[] = {68 ,35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82};
    // int arr[] = {1, 2, 5, 3, 4};
    // int arr[] = {1, 2, 3, 6, 5, 4};
    int arr[] = { 1, 2, 3, 5,  6, 4};
    int N = sizeof(arr)/sizeof(arr[0]);

    // find the index of the breaking number from end
    int prev = N-1;
    int i =N-1;
    while(i--){
        if(arr[i]<arr[prev]){
            prev= i;
            break;
        }
        prev= i;
    }
    if(prev == 0 && i <0){ 
        for(i=0;i<N/2;i++){
           
            int temp = arr[i];
            arr[i] = arr[N-1-i];
            arr[N-1-i]=temp;
        }
        printArr(arr,N);
        return 0;
    }

 
    // printArr(arr,N);
    // cout << endl;
    int start =prev+1;
    int len = N-(start);
    if(len == 1){ 
         int temp =arr[N-1];
         arr[N-1] = arr[prev];
         arr[prev] = temp; 
    } else{
        //swap next greater number of arr[prev] and arr[prev] 
        int next = prev+1;
        for(int i=prev+2;i<N;i++){
            if(arr[next]>arr[i] && arr[i]>arr[prev]){
               next = i;
            }
        }
        
        int temp = arr[next];
        arr[next] = arr[prev];
        arr[prev] = temp;
     
        for(int i=0;i<len/2;i++){
            int temp = arr[start+i];
            arr[start+i] = arr[len-1-i +start];
            arr[len-1-i +start] = temp;
        }
    }
    
    cout << prev << " -- " << len <<endl;
    printArr(arr,N);
    return 0;
}