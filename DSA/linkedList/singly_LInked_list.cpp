/* Singly linked list is a type of data
structure that is made up of nodes that are created
using self referential structures. Each of these nodes contain two parts,
 namely the data and the reference to the next list node. Only the
 reference to the first list node is required to access the whole
 linked list. This is known as the head. The last node in the list points
 to nothing so it stores NULL in that part. */

//  Malloc is used for dynamic memory allocation and is useful when you dont know 
// the amount of memory needed during compile time.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insert(int new_data)
{
    // struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void displayAll()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data;
        if (ptr->next != NULL)
            cout << "-> ";
        ptr = ptr->next;
    }
    cout << endl;
}

void DeleteMiddleNode()
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    struct Node *prev = NULL;
    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            prev = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        prev->next = slow_ptr->next;
        cout << "middle element: " << slow_ptr->data << endl;
        delete(slow_ptr);
    }
}

void printMiddleNode(){
    struct Node *slow_ptr=head;
    struct Node *fast_ptr=head;
    if(head!=NULL){
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    cout << "middle element: " << slow_ptr->data <<endl;
    }
}

void reverseList(){
    struct Node *curr=head;
    struct Node *next=NULL;
    struct Node *prev=NULL;
    while(curr!=NULL){
        next = curr->next;

        curr->next = prev;
        prev = curr;

        curr = next;
    } 
    head = prev; 
}

// reverse first k elements and next k elements
void reverseKElements(int k){
    if(!head || k==1) return;

    Node *dummy=new Node();
    dummy->data = -1;
    dummy->next = head;
   
   Node *prev=dummy,*curr=dummy,*next=dummy;

    int len=-1;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }

    
    cout << len <<endl;
    // int loop=len>k?k:len;
    while(next){
        curr=prev->next;
        next = curr->next;

        int loop= len>k? k:len;
        for(int i=1;i<loop;i++){
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next; 
        }
        prev=curr;
        loop-=k;
        // loop=len-k;
    }
    head=dummy->next;
    cout << len <<endl;
}

void removeDuplicates(){
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete(curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main()
{
    insert(3);
    insert(8);
    insert(10);
    insert(1);
    insert(4);
    insert(15);
    insert(4);
    insert(4);
    insert(1);
    
    displayAll();
    cout << endl;
    removeDuplicates();
    // DeleteMiddleNode();
    // printMiddleNode();
    // reverseKElements(2);
  
    reverseList();
    displayAll();
}