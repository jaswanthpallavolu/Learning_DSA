

#include <iostream>
using namespace std;

// How can you reverse a string?
void reverseString(string word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; i++)
    {
        char temp = word[len - 1 - i];
        word[len - 1 - i] = word[i];
        word[i] = temp;
    }
    cout << word << endl;
}

// Determine the second largest element of an array.
int *QuickSort(int arr[], int N)
{

    int i, j, min, temp;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[min] > arr[j])
                min = j;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return arr;
}
int main()
{
    // reverseString("jaswanth");
    // int arr[5] = {50, 12, 5, 17, 20};
    // int N = sizeof(arr) / sizeof(arr[0]);
    // int *s_arr = QuickSort(arr, N);
    // for (int i = 0; i < N; i++)
    //     cout << s_arr[i] << ",";

    // string name = "jaswanth";
    // cout << name.length() << endl;
    // for (string::reverse_iterator i = name.rbegin(); i < name.rend(); i++)
    //     cout << *i;

    int n = 1024;
    int r = 0;
    int c = 0;
    while (n != 0)
    {
        n = n / 10;
        ++c;
    };
    cout << "count: " << c << endl;
    return 0;
}