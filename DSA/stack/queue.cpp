#include<iostream>
using namespace std;

// #define SIZE 1000
class Queue{
    int *arr;
    int front,rear,size;

    Queue(int size);
    ~Queue();

    void enqueue(int data);
    int dequeue();
    void display();
}

Queue::Queue(int size){
    this.size = size;
    front=0;
    rear=0;
    arr = new int[size];
}
Queue::~Queue(){
    delete[] arr;
}

void Queue::enqueue(int data){
    if(rear < size){
        arr[rear]=data;
        cout << "inserted: "<<arr[rear] <<endl;
        rear++;
    }else{
        cout << "queue is full";
    }
}

int Queue::dequeue(){
    if(front == rear){
        cout << "queue is empty";
    }else{
        cout << "element removed: " << arr[front]<<endl;
        for(int i=0;i<rear-1;i++)
            arr[i] = arr[i+1];
        rear--;
    }
}

void Queue::display(){
    
}

int main(){
    return 0;
}