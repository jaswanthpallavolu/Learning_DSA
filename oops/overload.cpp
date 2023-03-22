#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    A(){
       cout << "super class" <<endl ;
    }
    void m1(){
        cout << "method in super class" <<endl ;
    }
    void m2(int a){
        cout << "method in super class "<< a <<endl ;
    }

};

class B:public A{
    public:
    B(){
        cout <<"sub class" <<endl;
    }
     void m1(){
        cout << "method in sub class" <<endl ;
    }
    void m2(char a){
        cout << "method in sub class "<< a <<endl ;
    }
};

int main(){
    B obj1 = B();
    // obj1.m1();
    obj1.m2(25);
    obj1.m2('B');
    cout << endl;

    // B obj2 = B();
    // obj2.m1();
    // obj2.m2(3);
}