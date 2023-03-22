#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout << "A constructor" <<endl;
    }
};
class B:A{
    public:
    B(){
        cout <<"B constructor" <<endl;
    }
};

int main(){
    A obj;

}