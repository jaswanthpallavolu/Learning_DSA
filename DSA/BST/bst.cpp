#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
}*root=NULL;

void insert(int key){
    Node *new_node = new Node();
    new_node->data=key;
    new_node->left=NULL;
    new_node->right=NULL;
    if(!root){
        root=new_node;
        return;
    }

    Node *prev=NULL;
    Node *temp=root;
    while(temp){
        if(temp->data>key){
            prev=temp;
            temp=temp->left;
        }else{
            prev=temp;
            temp=temp->right;
        }
    }

    if(prev->data > key)
        prev->left=new_node;
    else prev->right=new_node;
}

// Utiltiy function to print inorder traversal
void inorder(){
    Node *temp=root;
    stack<Node*> s;
    while(temp !=NULL || !s.empty()){
        if(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }else{
            temp=s.top();
            s.pop();
            cout << temp->data <<" ";
            temp=temp->right;
        }
    }
}

int main(){
    insert(30);
    insert(50);
    insert(15);
    insert(20);
    insert(10);
    insert(40);
    insert(60);

    inorder();
    return 0;
}