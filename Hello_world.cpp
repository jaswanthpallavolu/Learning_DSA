#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Compare
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        int disA = a[0] * a[0] + a[1] * a[1];
        int disB = b[0] * b[0] + b[1] * b[1];
        return disA < disB;
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int k);
vector<int> topKFrequent(vector<int> &nums, int k);

int main()
{
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 2;
    vector<int> nums = {1, 2, 1, 2, 3, 1, 3, 3, 3};

    vector<int> res = topKFrequent(nums, k);

    cout << endl;
    for (auto i : res)
    {
        cout << i << endl;
    }
    // for (auto set : res)
    // {
    //     for (auto i : set)
    //     {
    //         cout << i << ", ";
    //     }
    //     cout << endl;
    // }
}
struct MapCompare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (auto num : nums)
    {
        map[num]++;
    }
    vector<vector<int>> arr(nums.size() + 1);
    vector<int> result;
    for (auto pair : map)
    {
        arr[pair.second].push_back(pair.first);
    }
    for (int i = nums.size(); i >= 1; i--)
    {
        for (auto num : arr[i])
        {
            result.push_back(num);
            if (k == result.size())
                break;
        }
        if (k == result.size())
            break;
    }
    return result;
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;
    for (auto point : points)
    {
        max_heap.push(point);
        if (max_heap.size() > k)
        {
            max_heap.pop();
        }
    }
    vector<vector<int>> res;
    while (!max_heap.empty())
    {
        res.push_back(max_heap.top());
        max_heap.pop();
    }
    return res;
}