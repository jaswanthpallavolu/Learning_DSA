// https://www.geeksforgeeks.org/doubly-linked-list/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

} *head = NULL;

// Add a node at the front: (A 5 steps process)
// void 



int main(){
    // string str;
    // getline(cin,str);
    // cout << str;
    int n;
    cin >> n;
    int arr[n];
    int i=0;
    while(n--) cin >> arr[i++];
    for(auto x:arr) cout <<x;
    return 0;
}

