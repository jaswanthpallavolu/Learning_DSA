#include<iostream>
#include<map>
using namespace std;

int main(){
    string s ="abcabcbb";
    int lg=1,n=s.length();
    map<char,int> m;

    if(n==0) lg=0;
    for(int i=0;i<n-1;i++){
        m[s[i]]++;
        for(int j=i+1;j<n;j++){
            // int l =s.substr(i,j-i).length();
            if(++m[s[j]]==2)break;
            int l=j-i+1;
            if(l > lg) lg = l;
           
        }
        m.clear();
    }
        
    cout << lg;
    return 0;
}