#include<bits/stdc++.h>
using namespace std;

bool jumpGame(){
    // max projectile distance reached
    // int nums[]={2,3,1,1,4};
    int nums[]={3,2,1,0,4};
    int n = sizeof(nums)/sizeof(nums[0]);

    int maxR=0;
    for(int i=0;i<n;i++){
        if(maxR<i) return false;
        maxR=max(maxR,i+nums[i]);
    }
    return true;

}

int jumpGame2(){
    int nums[]={2,3,1,1,4};
    int n = sizeof(nums)/sizeof(nums[0]); 

    int steps=nums[0], maxR=nums[0];
    int jumps=1;
    if(n==1) return 0;
    if(steps==0) return -1;
    

    for(int i=1;i<n;i++){
        if(i==n-1) return jumps;
        maxR=max(maxR,i+nums[i]);
        steps--;

        if(steps==0){
            if(maxR<=i) return -1;
            jumps++;
            steps=maxR-i;
        }
    }


    return jumps;
}

int main(){
    // cout <<"can reach n-1: "<< jumpGame();
    cout <<"min jumps: " <<jumpGame2();
    return 0;
}