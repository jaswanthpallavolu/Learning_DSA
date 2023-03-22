// https://www.programiz.com/dsa/binary-tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *insertNode(int data){
    // Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    Node *new_node=new Node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return (new_node);
}

void printLevelOrder(Node *root);
void printCurrentLevel(Node *node,int level);
int maxDepth(Node *node);

// height of tree
int maxDepth(Node *node){
    if (node==NULL) return 0;
    int left=maxDepth(node->left);
    int right=maxDepth(node->right);
    return max(left,right)+1;
}

// *** USING QUEUE for reverse we use stack
void printLevelOrderQueue(Node *root){
    if(root==NULL) return;

    stack<Node *> s;
    queue<Node *> q;
    q.push(root);

    while(q.empty() == false){
        root = q.front();
        s.push(root);
        // cout << root->data << " ";
        q.pop();

        if(root->right != NULL)
            q.push(root->right);
         if(root->left != NULL)
            q.push(root->left);
    }

    while(s.empty()==false){
        cout << s.top()->data << " ";
        s.pop();
    }
}
void levelOrder(Node *node){
    if(!node) return;
    cout << node->data << " ";
    levelOrder(node->left);
    levelOrder(node->right);

}



// *** USING RECURSION
void printLevelOrder(Node *root){
    int h=maxDepth(root);
    for(int i=1;i<=h;i++)
        printCurrentLevel(root, i);
cout <<"\n";
    // for reverse level order
    for(int i=h;i>0;i--)
        printCurrentLevel(root, i);

    // levelOrder(root);
}

void printCurrentLevel(Node *node,int level){
    if (node == NULL) return;
    if (level == 1) cout << node->data << " ";
    else if (level > 1) {
        
        printCurrentLevel(node->left, level - 1);
        printCurrentLevel(node->right, level - 1);
    }
}

int main(){
    Node *root = insertNode(1);
    root->left = insertNode(2);
    root->right = insertNode(3);
    root->left->left = insertNode(4);
    root->left->right = insertNode(5);

    // cout << "max depth of btree: " << maxDepth(root) <<endl;
    
    cout <<"level order Traversel: ";
    printLevelOrder(root);
    // printLevelOrderQueue(root);
    cout << endl;

    return 0;
}

// class btree{
//     public:
//         btree();
//         // ~btree();

//         void insert(int data);
//         node *search(int data);

//     private:
//         void insert(int data,node *leaf );
//         node *search(int data, node *leaf);

//         node *root;
// };

// btree::btree(){root=NULL;}
// void btree::insert(int data,node *leaf){}