#include <bits/stdc++.h>
using namespace std;



int main(){
    int A[] = { 2, 4, 5,3, 6 };
    int N = sizeof(A) / sizeof(int);

    

    for(int i=1;i<N;i++){
        int curr=A[i];
        int j=i-1;
        while(A[j]>curr && j>=0){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=curr;
        
    }

    for(int i=0;i<N;i++){
        cout << A[i] <<" ";
    }

    // int max= *max_element(A,A+N);

    // vector<int> freq(max+1,0);
    // for(int i=0;i<N;i++)
    //     freq[A[i]]++;

    // vector<int> res(max+1,0);
    // for(int i=1;i<=max;i++){
    //     for(int j=i;j<=max;j+=i){
    //         if(i==j){
    //             res[i]+=(freq[j]-1);
    //         }
    //         else{
    //             // case1
    //             res[i]+=freq[j];
    //             // case2
    //             res[j]+=freq[i];
    //         }
    //     }
    // }

    // for (int i = 0; i < N; i++) 
    //     cout << res[A[i]] << " ";
}