// QUESTION : https://codeforces.com/contest/1552/problem/B
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        int spr = 0;

        cin >> n;
        int arr[n][5];
        // input
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }

        //output
        for (int i = 1; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < 5; j++)
            {

                if (arr[spr][j] > arr[i][j])
                    c++;
            }
            if (c >= 3)
                spr = i;
            // cout << "O/P: " << c << spr << endl;
        }

        for (int i = 0; i < spr; i++)
        {
            int c = 0;
            for (int j = 0; j < 5; j++)
            {
                if (arr[spr][j] > arr[i][j])
                    c++;
            }
            if (c >= 3)
            {
                spr = -1;
                break;
            }
        }

        if (spr != -1)
        {
            spr++;
        }
        cout << spr << endl;
    }

    return 0;
}