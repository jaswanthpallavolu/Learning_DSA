#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int block;

struct Query{
    int L,R;
};

bool compare(Query x, Query y){
    if(x.L/block != y.L/block)
        return x.L/block < y.L/block;
    
    return x.R < y.R;
}

void MOalgo(int a[],int n,Query q[],int m){
    block = int(sqrt(n));

    sort(q, q+m, compare);

    int currL=0, currR=0, currSum=0;

    //traverse through all queries
    for(int i=0;i<m;i++){
        int L=q[i].L, R=q[i].R;

        while(currL < L)
            currSum -= a[currL++];

        while(currL > L){
            currSum += a[currL-1];
            currL--;
        }

        while (currR <= R)
            currSum += a[currR++];
        
        while (currR > R+1){
            currSum -= a[currR-1];
            currR--;
        }

        cout << "Sum of [" << L << ", " << R<< "] is "  << currSum << endl;
    }
}

int main(){
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    MOalgo(a, n, q, m);
    return 0;
}