#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
}*head=NULL;

void printList(){
    Node *ptr=head;
    while(ptr != NULL){
        cout << ptr->data << " -> ";
        ptr=ptr->next;
    }
    cout <<endl;
}

void insert(int data){
    Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head=ptr;
}

void reverse(){
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr=next;
    }
    head = prev;
}

void printMiddleNode(){
    Node *prev=head,*next=head,*list=NULL;
    while(next !=NULL && next->next !=NULL){
        list = prev; 

        prev = prev->next;
        next=next->next->next;
    }
    cout << endl;
    cout << "middle Node: " << prev->data <<endl;
    list->next = prev->next;
    // head = list;
}

void reverseBothParts(int k){
    //  || k==1
    if(!head) return;

    Node *dummy=(struct Node*)malloc(sizeof(struct Node));
    dummy->data = -1;
    dummy->next =head;

    Node *prev=dummy,*curr=dummy, *next=dummy;

    int count = 0;
    while(curr){
        curr=curr->next;
        count++;
    }
    int loop = count > k? k:count-1;
    while(next){
        curr=prev->next;
        next=curr->next;

        for(int i=1;i<loop;i++){
            curr->next=next->next;

            next->next=prev->next;
            prev->next=next;

            next=curr->next;
        }
        prev=curr;
        loop=count-k-1;
    }

    head = dummy->next;
    cout<<endl;
    
}

int main(){
    insert(3);
    insert(10);
    insert(4);
    insert(12);
    insert(6);
    insert(1);

    printList(); 
    // reverse();cout << endl;
    // printList();

    // printMiddleNode();cout << endl;
    // printList();
    reverseBothParts(1);
    printList(); 

    return 0;
}