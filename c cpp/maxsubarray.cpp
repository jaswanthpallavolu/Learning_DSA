#include<iostream>
#include<vector>
using namespace std;



// Kadane’s algorithm
int maxSubArr(vector<int> arr){
    int max_so_far = INT_MIN,sum = 0;
    for(auto i=arr.begin();i!=arr.end();i++){
        sum += *i;
        if(max_so_far < sum)
            max_so_far = sum;
        if(sum <0)
            sum= 0;
    }
    return max_so_far;
}

struct Pair
{
    int min;
    int max;
};

void reverse(int arr[],int start,int end){
    if(start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse(arr,start+1,end-1);
}

void printArray(int arr[],int n){
    cout << ' ';
    for(int i=0;i<n;i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int minJumps(int arr[], int n){
        // Your code here
        int minjumps = 0,i=0;
        if (n == 1) return minjumps;
        while(n >1 && i<=n-1){
            // cout<<"i:" << i << " parr: " << arr[i]<<" jump:" <<minjumps <<endl;
            if(arr[i] == 0 && i < n-1) return -1;
            else if(arr[i] + i >= n-1) return minjumps + 1;
            else{
                
                int l = 0;
                int s;
                //find largest posible step which has high value 
                for(int j=0;j<arr[i];j++){
                    if(arr[l+i+1] < arr[j+i+1]) l = j;
                }
                for(int j=0;j<arr[i];j++){
                    s = arr[arr[j+i+1]];
                    cout <<j+i+1 <<" " << arr[j+i] <<"-" << s << " "<<  s+ j+i+1 <<endl;
                    if(s+ j+i+1 >= n-1  && (arr[l+1] > s) && s != 0)
                        return minjumps + 2;
                }
                // cout << "large " << arr[l+i+1] << endl;
                // if(arr[i] + i >= n-1) return minjumps + 1;
                i += l+1;
                minjumps++;
                if(i >=n-1) return minjumps;
                cout << endl; 
            }
        }
        return -1;
}

int main(){
    // vector<int> arr ={-2,1,-3,4,-1,2,1,-5,4};
    // cout << "sum: " << maxSubArr(arr) <<endl;

    // struct Pair minmax;
    // minmax.max =0;
    // minmax.min = 0;

    // why arr is acting as a global variable when we parse this array in a function 
    // sol:- The parameter int[] is exactly the same as int*, a pointer to an int.
    
    int arr[] = {2 ,1 ,0 ,3};
    // int arr[] ={1};
    // int arr[] = {2, 3, 1 ,1, 2, 4, 2, 0, 1, 1};
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    // int arr[] = {9,10,1,2,3,4,8,0,0,0,0,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    // reverse(arr,0,n-1);
    // printArray(arr,n);
    cout << minJumps(arr,n);
    return 0;
}