// https://codeforces.com/problemset/problem/4/A
//not solved
#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a >= 1 && a <= 100)
    {
        if (a % 2 == 0)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}