#include<bits/stdc++.h>
using namespace std;

// arr should not be 
// sub array lenth not specified

int main(){
    int arr[] = {8,2,4,1,1,5,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 6;

    int sum=0,s=0;
    int maxlen=INT_MIN;

    for(int i=0;i<n;i++){
        sum += arr[i];
        while(sum > target && s<n){
            sum -= arr[s++];
        }

        if(sum == target){
            cout << s <<" " <<i<<endl;
            maxlen = max(maxlen, i-s+1);
        }
        
    }
    cout << maxlen ;
}