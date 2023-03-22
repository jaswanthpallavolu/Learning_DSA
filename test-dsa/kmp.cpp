// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string pat = "AAACAAAA";
    int n = pat.size();
    vector<int> lps(n,0);
    int len = 0,i=1;
    while(i<n){
        if(pat[len] ==pat[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else if(pat[len]!=pat[i] && len>0)
            len=lps[len-1];
        
        else if(pat[len]!=pat[i] && len==0) i++;
    }

    for(auto n:lps)
    cout << n <<", ";
}