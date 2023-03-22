#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

// A Queue Node
struct Node
{
    int x, y, dist;
};

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(vector<vector<int>> const &mat, vector<vector<bool>> &visited,
             int row, int col)
{
    return (row >= 0 && row < mat.size()) && (col >= 0 && col < mat[0].size()) && mat[row][col] && !visited[row][col];
}

int ShortestPathLength(vector<vector<int>> const &mat, pair<int, int> &src,
                       pair<int, int> &dest)
{

    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
        mat[dest.first][dest.second] == 0)
    {
        return -1;
    }

    int M = mat.size();
    int N = mat[0].size();

    vector<vector<bool>> visited;
    visited.resize(M, vector<bool>(N));

    queue<Node> q;

    int i = src.first;
    int j = src.second;

    visited[i][j] = true;
    q.push({i, j, 0});

    int min_dist = INT_MAX;

    while (!q.empty())
    {

        Node node = q.front();
        q.pop();
        int i = node.x, j = node.y, dist = node.dist;
        if (i == dest.first && j == dest.second)
        {
            min_dist = dist;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            if (isValid(mat, visited, i + row[k], j + col[k]))
            {
                visited[i + row[k]][j + col[k]] = true;
                q.push({i + row[k], j + col[k], dist + 1});
            }
        }
    }

    if (min_dist != INT_MAX)
    {
        return min_dist;
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;
    int a;
    vector<vector<int>> mat;
    for (int i = 0; i < N; i++)
    {
        vector<int> x;
        for (int j = 0; j < N; j++)
        {
            cin >> a;
            x.push_back(a);
        }
        mat.push_back(x);
    }
    vector<vector<int>> T(mat[0].size(), vector<int>());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            T[j].push_back(mat[i][j]);
        }
    }
    mat = T;

    for (int i = 0; i < N; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }

    pair<int, int> src;
    pair<int, int> dest;
    char dummy;
    // cout << "enter source :" << endl;
    cin >> src.first;
    cin >> dummy;
    cin >> src.second;
    // cout << "enter destination :" << endl;
    cin >> dest.first;
    cin >> dummy;
    cin >> dest.second;

    int min_dist = ShortestPathLength(mat, src, dest);
    // cout << endl;
    if (min_dist != -1)
    {
        // cout << "The shortest path from source to destination has length "
        cout << min_dist;
    }
    else
    {
        cout << "Destination cannot be reached from a given source";
    }

    return 0;
}