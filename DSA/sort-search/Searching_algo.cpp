#include <iostream>
#include <bits/stdc++.h> //STL
// #include <array>

// #include<bits/stdc++.h>
//     binary_search()
//     upper_bound()
//     lower_bound()
//     binary_search(start_ptr, end_ptr, ele)

using namespace std;

int Linear_Search(int arr[], int N, int X);
int Binary_Search(int arr[], int N, int X);

int main()
{
    int arr[] = {25, 46, 12, 9, 30, 60, 75, 10};
    int N = sizeof(arr) / sizeof(arr[0]);
    int result1 = Linear_Search(arr, N, 30);
    cout << "linear Search: " << result1 << endl;

    int result2 = Binary_Search(arr, N, 30);
    cout << "Binary Search(recursive): " << result2 << endl;
    return 0;
}

int Linear_Search(int arr[], int N, int X)
{
    int i;
    for (int j = 0; j < N; j++)
    {
        if (arr[j] == X)
            return j;
    }
    return -1;
}

// Selection sort
int *QuickSort(int arr[], int N)
{
    int i, j, min, temp;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int Recursive(int arr[], int l, int r, int X)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == X)
            return mid;

        if (arr[mid] > X)
            Recursive(arr, l, mid - 1, X);
        Recursive(arr, mid + 1, r, X);
    }
    return -1;
}

int Binary_Search(int arr[], int N, int X)
{
    int *s_arr = QuickSort(arr, N);
    // for (int i = 0; i < N; i++)
    //     cout << s_arr[i] << " - ";
    return Recursive(s_arr, 0, N, X);
}