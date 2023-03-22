#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool isValid(int x, int y, int N)
{
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}

struct newNode
{

    int x, y, dist;
    newNode(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {}
    bool operator<(const newNode &i) const
    {
        return x < i.x || (x == i.x && y < i.y);
    }
};

int ShortestDistance(int N, newNode src, newNode dest)
{

    set<newNode> visited;
    queue<newNode> q;
    q.push(src);

    while (!q.empty())
    {
        newNode node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if (x == dest.x && y == dest.y)
            return dist;

        if (!visited.count(node))
        {

            visited.insert(node);

            for (int i = 0; i < 8; i++)
            {
                int x1 = x + row[i];
                int y1 = y + col[i];
                if (isValid(x1, y1, N))
                    q.push({x1, y1, dist + 1});
            }
        }
    }

    return INT_MAX;
}

int main()
{
    int N = 8;
    newNode src = {0, 0}, dest = {0, 0};
    cin >> src.x;
    cin >> src.y;
    cin >> dest.x;
    cin >> dest.y;

    cout << ShortestDistance(N, src, dest);

    return 0;
}