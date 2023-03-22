#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
}*root=NULL;


Node *insertNode(int data){
    // Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    Node *new_node=new Node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return (new_node);
}

vector<vector<int>> printZigZag(Node *root){
    vector<vector<int>> res;
    vector<int> elements;
    
    queue<pair<Node*,int>> q;
    q.push({root,0});
    int prev = 0,lvl;

    while(!q.empty()){
        Node *temp=q.front().first;
        lvl = q.front().second;
        q.pop();

        if(prev==lvl) elements.push_back(temp->data);
        else{
            
            if(prev%2!=0) reverse(elements.begin(),elements.end());
            res.push_back(elements);
            
            elements.clear();
            prev=lvl;
            elements.push_back(temp->data);
        }

        if(temp->left) q.push({temp->left,lvl+1});
        if(temp->right) q.push({temp->right,lvl+1});

    }
    if(prev%2!=0) reverse(elements.begin(),elements.end()) ;
    res.push_back(elements);
    return res;
    
}
int main(){
    Node *root = insertNode(3);
    root->left = insertNode(9);
    root->right = insertNode(20);
    root->right->left = insertNode(15);
    root->right->right = insertNode(7);

    for(auto x:printZigZag(root)){
        cout <<"\n";
        for(auto y:x)
            cout <<y<<", ";
        
    }
    return 0;
}