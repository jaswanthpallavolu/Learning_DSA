#include <bits/stdc++.h>

using namespace std;

bool isExist(int N, int i, int j)
{
    if (i < 0 || i >= N)
        return false;
    if (j < 0 || j >= N)
        return false;
    return true;
}

void check(int **Arr, int N, int i, int j)
{
    if (isExist(N, i, j) && Arr[i][j] == 1)
    {
        Arr[i][j] = 0;
        //PREV ROW
        check(Arr, N, i - 1, j - 1);
        check(Arr, N, i - 1, j);
        check(Arr, N, i - 1, j + 1);
        //CURRENT ROW
        check(Arr, N, i, j - 1);
        check(Arr, N, i, j + 1);
        //NEXT ROW
        check(Arr, N, i + 1, j - 1);
        check(Arr, N, i + 1, j);
        check(Arr, N, i + 1, j + 1);
    }
}

int TotalIslands(int **Arr, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (Arr[i][j] == 1)
            {
                count++;
                check(Arr, N, i, j);
            }
    }
    if (count == 0)
        return 0;
    return count;
}

int main()
{
    int N;
    // cout << "Enter the n value : ";
    cin >> N;
    int **Arr = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++)
        Arr[i] = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Arr[i][j];
    // cout << "Total Number of islands : "
    cout << endl
         << TotalIslands(Arr, N) << endl;
    return 0;
}