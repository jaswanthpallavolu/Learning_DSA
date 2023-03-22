#include <iostream>
#include<string>
#include<vector>

using namespace std;

void happyPrefix(string s){
    int N = s.length();
    string lg;
    
    for(int i=0;i<N-1;i++){
        string s1 = s.substr(0,i+1);
        string s2 = s.substr(N-1-i,i+1);

        cout << s1 << " " <<s2 <<endl;
        if(s1 == s2 && lg.length()<s2.length()){
            lg = s1;
        }
    }
    cout << "lg: " << lg;
}

string KMPLPS(string s){
    int n=s.size();
    vector<int>lps(n,0);
    int i=1,len=0;

    while(i<n){
        if(s[i]==s[len])lps[i++]=++len;    
        else{
            if(len) len=lps[len-1];   
            else i++;
        }
    }
    return s.substr(0,len); 
}

int main(){
    string s="ababab";
    // happyPrefix(s);
    cout << KMPLPS(s);
    return 0;
}