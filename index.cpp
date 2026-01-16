#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> subsets(vector<int> &nums);
vector<vector<int>> permute(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (auto set : res)
    {
        for (auto i : set)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> perms;
    perms.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
        int permsLen = perms.size();
        vector<vector<int>> newPerms;
        for (int j = 0; j < permsLen; j++)
        {
            int start = 0;
            vector<int> currPerm = perms[j];
            int n = currPerm.size();
            vector<int> curr;
            for (int start = 0; start <= n; start++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (start == k)
                        curr.push_back(nums[i]);
                    curr.push_back(currPerm[k]);
                }
                if (start == n)
                    curr.push_back(nums[i]);
                newPerms.push_back(curr);
                curr.clear();
            }
        }
        perms = newPerms;
    }
    return perms;
}
