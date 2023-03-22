#include<bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2,int m,int n,vector<vector<int>>& dp){
    if(m<0||n<0) return 0;

    if(dp[m][n]!=-1) return dp[m][n];

    if(str1[m]==str2[n]) return dp[m][n]= 1+LCS(str1,str2,m-1,n-1,dp);    
    return dp[m][n]= max(LCS(str1,str2,m-1,n,dp) , LCS(str1,str2,m,n-1,dp));
}

int LCSub(string str1,string str2,int m,int n){
    int dp[2][min(m,n)];
    int res=0;
    dp[0][0]=0;
    // space optimized approach O(min(m,n))
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                if( dp[i%2][j] > res) res =  dp[i%2][j];
            }else  dp[i%2][j]=0;
        }
    }
    return res;
}


void minInsertions(string str1,string str2){
    int m=str1.length(),n=str2.length();
    vector<vector<int>> dp1(m,vector<int>(n,-1));
    vector<vector<int>> dp2(m,vector<int>(n,-1));
    cout <<"longest sub sequence " << LCS(str1,str2,m-1,n-1,dp1) <<endl;
    cout <<"longest sub string " <<LCSub(str1,str2,m,n);
    // vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    // cout << m-LCS(str1,str2,m,n,dp);
}

int main(){

    // subsequence
    string str = "xyza1bc";
    string rev = "xabcdefg";//o/p = 3
    
    // substring

    // reverse(rev.begin(),rev.end());

    minInsertions(str,rev);
    // cout << minCharReq(str);
    return 0;
}


int minCharReq(string str){
    int n=str.size();
    if(n<=1) return 0;
    string p=str;
    reverse(p.begin(),p.end());
    if(p==str) return 0;

    queue<char> s;
    while(n-->1) s.push(str[n]);
    string s1,str1,p1;
    int count=0;
    while(!s.empty()){
        s1+=s.front();
        // cout << s1 <<",";
        // strcat(s1,s.top());
        s.pop();
        count++;

        str1 = s1;
        str1+=str;
        // strcat(str1,str);
        p1=str1;
        reverse(p1.begin(),p1.end());
        if(p1==str1) return count;
    }

    return 0;
}