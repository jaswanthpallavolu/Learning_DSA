#include <iostream>
#include<stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,1,2};
    int p =nums[0];
    int count =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=p){
                    p=nums[i];
                    nums[count]=nums[i];
                    count++;
                }
        }
   for(int i=0;i<count;i++){
       cout << nums[i] << ' ';
   }
}