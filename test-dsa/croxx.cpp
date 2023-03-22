#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="ZOPSMARTHIRING";
    int b = 3;

    vector<vector<char>> vec(b,vector<char>(b));
    int down=true;
    int c=0;
    string ans="";

    for(int i=0;i<s.length();i++){
        if(down){
            vec[c%b].push_back(s[i]);
            c++;
        }
        else{
            vec[c%b].push_back(s[i]);
            c--;  
        }

        if(c==b && down==true){
            down=false;
            c=1;
        }else if(c==0 && down==false){ 
            down=true;
        }
    }

    cout << endl;


    for(auto x:vec){
        for(auto y:x){
            // ans+=y;
            cout << y <<" ";
        }
        cout << endl;
    }
    cout << ans;
}