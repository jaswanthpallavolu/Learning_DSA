#include <iostream>
using namespace std;

class Recursive
{
public:
    int fibonacci(int n)
    {
        if (n <= 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main()
{
    Recursive rec;
    cout << "fibonacci series: " << rec.fibonacci(5);
    return 0;
}