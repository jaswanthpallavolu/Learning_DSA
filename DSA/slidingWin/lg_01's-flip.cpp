// C++ program for the above approach
//https://www.geeksforgeeks.org/longest-subarray-of-only-0s-or-1s-with-atmost-k-flips/

#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray
// following the given conditions
int longestSubSeg(int arr[], int N, int K)
{
	int cnt = 0;
	int left = 0;
	int maximum_len1 = 0;
	int maximum_len0 = 0;

	// Finding length of maximum subarray
	// containing 1's only with atmost k flips
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0)
			cnt++;

		while (cnt > K) {
			if (arr[left] == 0)
				cnt--;
			left++;
		}
		maximum_len1 = max(maximum_len1, i - left + 1);
	}

	// Set these variables to 0 for further use
	cnt = 0;
	left = 0;

	// Finding length of maximum subarray
	// containing 0's only with atmost k flips
	for (int i = 0; i < N; i++) {
		if (arr[i] == 1)
			cnt++;

		while (cnt > K) {
			if (arr[left] == 1)
				cnt--;
			left++;
		}
		maximum_len0 = max(maximum_len0, i - left + 1);
	}

	return max(maximum_len1, maximum_len0);
}

// Driver code
int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 0, 1 };
	int K = 2;
	int N = sizeof(arr) / sizeof(arr[0]);

    cout << 'hh';
	// Function call
	cout << longestSubSeg(arr, N, K);
	return 0;
}
