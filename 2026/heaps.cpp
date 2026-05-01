#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<T, Container, Comparator>
    // greater<int> a > b
    // less<int> a < b
    priority_queue<int> max_heap;                            // max heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // min heap
}