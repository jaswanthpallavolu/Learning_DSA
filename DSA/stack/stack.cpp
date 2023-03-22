#include<iostream>
using namespace std;

int stack[20], n=20, top=-1;
void push(int val){
    if(top>=n-1)
     cout <<"Stack Overflow"<<endl;
    else{
        top++;
        stack[top] = val; 
    }
}
void pop(){
    if(top<0)
        cout<<"Stack Underflow"<<endl;
    else{
        cout <<"the popped element: " <<stack[top]<<endl;
        top--;
    }
}
void peek(){
    if(top<0)
        cout<<"No elements in the stack"<<endl;
    else cout <<"peek element: "<<stack[top] <<endl;
}
int main(){
    push(20);
    push(10);
    push(60);
    peek();
    pop();
    peek();
    return 0;
}