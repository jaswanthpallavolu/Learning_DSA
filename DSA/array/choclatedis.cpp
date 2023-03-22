#include <iostream>
using namespace std;

void quickSort(int arr[],int N){
    int i,j,min,temp;
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i+1;j<N;j++)
            if(arr[j]<arr[min])
                min =j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int TrappingRainWater(int arr[],int N){
    int i,dif,hsf = 0;
    int units = 0;
    int c = 0;

    for(i=0;i<N;i++){
        if(arr[i] == 0 && c ==0 ) break;
        if (arr[i] > hsf) hsf = arr[i];



        
    }
    return 0;
}

int main(){
    // int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    // int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    int arr[] = {1,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    int l=0,r=N-1,lmax=INT_MIN,rmax=INT_MIN,maxw=INT_MIN,water;

    while(l<r){
        lmax = max(arr[l],lmax);
        rmax = max(arr[r],rmax);

        if(lmax < rmax){
            water = (lmax)*(r-l);
            l++;
        }else{
            water = (rmax)*(r-l);
            r--;
        }
        // }else {
        //  water = (lmax)*(r-l);
        //  r--;   
        // }
        cout << lmax <<"," <<rmax<<"," << water <<endl;
        if(water>maxw) maxw = water;
        
    }
    cout <<maxw;

    // cout << "total units: "<<TrappingRainWater(arr,N) << endl;
    // quickSort(arr,N);
    // int m = 7,min=INT_MAX;

    // for(int i=0;i+m-1<N;i++){
    //     if(arr[i+m-1]-arr[i] < min)
    //         min=arr[i+m-1]-arr[i];
    // }
    // cout << "min diff: " << min;
    
    return 0;
}