#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n);
void recursion(int n, int &ways);

int main()
{
    int n = 3;
    cout << climbStairs(n);
}

int climbStairs(int n)
{
    int ways = 0;
    recursion(n, ways);
    return ways;
}

void recursion(int n, int &ways)
{
    if (n == 0)
    {
        ways++;
        return;
    }
    if (n - 1 >= 0)
        recursion(n - 1, ways);
    if (n - 2 >= 0)
        recursion(n - 2, ways);
}