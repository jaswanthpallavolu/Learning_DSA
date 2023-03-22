// https://www.geeksforgeeks.org/friend-class-function-cpp/
#include<iostream>
using namespace std;

class A{
    int x;
    public:
    A(){
        x=20;
    }

    friend class B;
    friend void frndFnc(A &obj);
    
};

class B{
    public:
    int y=10;

    void display(A &obj){
        cout << "x : " <<obj.x <<", y: "<<y <<endl;
    }

    
};
void frndFnc(A &obj){
        cout << "im inside friend fnc " <<obj.x;
}

int main(){
    A a;
    B b;
    b.display(a);
    frndFnc(a);
}