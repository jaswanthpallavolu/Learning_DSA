#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxTaxiEarnings(int n, vector<vector<int>> &rides);
long long recurr(vector<vector<int>> &rides, int p, vector<long long> &dp);
int main()
{
    int n = 5;
    vector<vector<int>> rides = {{2, 5, 4}, {1, 5, 1}};
    // vector<vector<int>> rides = {
    //     {1, 6, 1},
    //     {3, 10, 2},
    //     {10, 12, 3},
    //     {11, 12, 2},
    //     {12, 15, 2},
    //     {13, 18, 1}};
    cout << "maxTaxiEarnings: " << maxTaxiEarnings(n, rides);
}

// struct Compare{
//     vector<int> operator()(vector<int> &a, vector<int> &b){
//         return
//     }
// };

long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
{
    vector<long long> dp(rides.size(), 0);
    std::sort(rides.begin(), rides.end(), [](vector<int> &a, vector<int> &b)
              {
        if(a[1]==b[1]) return a[0] < b[0];
        return a[1]<b[1]; });

    return recurr(rides, -1, dp);
}

long long recurr(vector<vector<int>> &rides, int p, vector<long long> &dp)
{
    if (p >= 0 && dp[p])
        return dp[p];

    long long cost = 0;
    if (p >= 0)
        cost = rides[p][1] - rides[p][0] + rides[p][2];

    long long nextRidesCost = 0;
    for (int i = p + 1; i < rides.size(); i++)
    {
        if (p < 0 || rides[p][1] <= rides[i][0])
        {
            nextRidesCost = std::max(nextRidesCost, recurr(rides, i, dp));
        }
    }
    if (p >= 0)
        dp[p] = cost + nextRidesCost;
    return cost + nextRidesCost;
}