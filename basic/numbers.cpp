#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    int num = 0;
    int rev = 0;
    int c = 0;
    while (n != 0)
    {
        num += pow(n % 10, 3);
        rev = rev * 10 + (n % 10);
        n = n / 10;
        ++c;
    };
    cout << "count: " << c << endl;
    cout << num << endl;
    cout << "reverse: " << rev;
}