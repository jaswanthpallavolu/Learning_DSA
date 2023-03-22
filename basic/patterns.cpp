#include<iostream>
using namespace std;

void P1(){
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++) cout << j<<" ";
    //     cout<<endl;
    // }
    for(int i=5;i>0;i--){
        for(int j=i;j>0;j--) cout << j<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void P2(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++) cout << i<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void P3(){
    int c=1;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=i;j++) cout << c++<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void P4(int n){
    int k=2*(n-2),i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<k;j++) cout << " ";
        k-=1;
        for(j=0;j<i+1;j++) cout << "*" << " ";
        cout <<endl;
    }
}

void P5(int n){
    for(int row=0;row<2*n;row++){
        int c= row+1>n ? n-(row-n)-1:row+1;
        for(int col=0;col<c;col++)
            cout << "* ";
        cout << endl;
    }
}

int main(){
    // P1();
    // P2();
    // P3();
    // P4(4);
    P5(5);
    return 0;
}