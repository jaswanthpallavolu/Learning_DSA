#include <iostream>
using namespace std;

int main()
{
    // cout << "Hello 1234" << endl;
    // vector<int> arr = {3,0,1};
    int size = 6;
    int k = 2;
    int i = 0;
    while (i * k + 2 <= size)
    {
        cout << i * k + 1 << ", " << i * k + 2 << endl;
        i++;
    }
}
