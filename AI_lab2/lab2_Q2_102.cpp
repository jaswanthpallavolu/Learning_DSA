#include <iostream>
using namespace std;

#define M 4
#define N 4

void check(int arr[][N], int x, int y, int prevN, int newN)
{

    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (arr[x][y] != prevN)
        return;
    arr[x][y] = newN;
    check(arr, x + 1, y, prevN, newN);
    check(arr, x - 1, y, prevN, newN);
    check(arr, x, y + 1, prevN, newN);
    check(arr, x, y - 1, prevN, newN);
}

int forEveryNode(int arr[][N])
{

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] == 0)
                arr[i][j] = 2;

    for (int i = 0; i < M; i++)
        if (arr[i][0] == 2)
            check(arr, i, 0, 2, 1);

    for (int i = 0; i < M; i++)
        if (arr[i][N - 1] == 2)
            check(arr, i, N - 1, 2, 1);

    for (int i = 0; i < N; i++)
        if (arr[0][i] == 2)
            check(arr, 0, i, 2, 1);

    for (int i = 0; i < N; i++)
        if (arr[M - 1][i] == 2)
            check(arr, M - 1, i, 2, 1);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] == 2)
                arr[i][j] = 0;
    return 0;
}

int main()
{

    int arr[M][N];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    forEveryNode(arr);

    cout << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
