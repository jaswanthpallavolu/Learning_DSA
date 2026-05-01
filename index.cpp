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
void letterCasePermutation(string &s, int index, vector<string> &result);

int main()
{
    // string a = "1";
    // cout << static_cast<char>(std::tolower(static_cast<unsigned char>(a[0])));
    // vector<int> nums = {1, 2, 3};
    string s = "a1b2";
    vector<string> res;
    string currPerm;
    letterCasePermutation(s, 0, res);

    cout << endl;
    for (auto set : res)
    {
        for (auto i : set)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
}

void letterCasePermutation(string &s, int i, vector<string> &result)
{
    if (i == s.size())
    {
        result.push_back(s);
    }
    else
    {

        // for (int i = index; i < s.size(); i++)
        // {
        if (std::isdigit(static_cast<unsigned char>(s[i])))
        {
            letterCasePermutation(s, i + 1, result);
        }
        else
        {
            s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
            letterCasePermutation(s, i + 1, result);
            s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
            letterCasePermutation(s, i + 1, result);
        }
        // }
    }
}
