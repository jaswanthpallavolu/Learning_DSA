// https://www.spoj.com/problems/PRO/
#include <iostream>
#include <queue>
using namespace std;

int totalCostOfPrizes(const vector<vector<int>> &pro);
int main()
{
    // input
    vector<vector<int>> pro = {{1, 2, 3}, {1, 1}, {10, 5, 5, 1}, {}, {2}};
    cout << "totalCostOfPrizes: " << totalCostOfPrizes(pro);
}

int totalCostOfPrizes(const vector<vector<int>> &pro) // O(NlogN)
{
    priority_queue<int> max_heap;                            // max heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // min heap
    int total = 0;
    // for (int i = 0; i < pro.size(); i++)
    // {
    //     for (int j = 0; j < pro[i].size(); j++)
    //     {
    //         max_heap.push(pro[i][j]);
    //         min_heap.push(pro[i][j]);
    //     }
    //     total += max_heap.top() - min_heap.top();
    //     max_heap.pop();
    //     min_heap.pop();
    // }
    for (const auto &promotion : pro)
    {
        for (int x : promotion)
        {
            max_heap.push(x); // O(logN)
            min_heap.push(x);
        }
        if (!(max_heap.empty() || min_heap.empty()))
        {
            total += max_heap.top() - min_heap.top();
            max_heap.pop();
            min_heap.pop();
        }
    }
    return total;
}