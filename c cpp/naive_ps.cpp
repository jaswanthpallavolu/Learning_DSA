#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    int m = strlen(pat);
    int n = strlen(txt);
    int s, count;
    for (int i = 0; i + m <= n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
        // else
        //     cout << "error";
    }
    return 0;
}