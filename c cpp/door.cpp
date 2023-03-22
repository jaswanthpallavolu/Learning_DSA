// https://codeforces.com/contest/1644/problem/A
#include <iostream>
#include<stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
vector<char> keys;

int getIndex(char c){
    auto it = find(keys.begin(),keys.end(),c);
    if(it!=keys.end()) return it-keys.begin();
    else return -1;
}
int canOpenALL(string str){
    for(auto i=str.begin();i!=str.end();i++){
        switch(*i){
            case 'R': 
            if (getIndex('r')==-1) return 0;
                break;
            case 'G':
              if (getIndex('g')==-1) return 0;
                break;
            case 'B':
              if (getIndex('b')==-1) return 0;
                break;
            default: keys.push_back(*i);
        }
    }
    keys.clear();
    return 1;
}
int main(){
    int n;
    cin >> n;
    while(--n){
        string str;
        cin >> str;
        if(canOpenALL(str)) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}