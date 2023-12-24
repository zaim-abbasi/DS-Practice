#include <iostream>
using namespace std;
int Print(int x)
{
    if (x == 0)
        return 0;
    cout << x << " ";
    Print(x - 1);
}

int PrintReverse(int x)
{
    if (x <= 0)
        return 0;
    PrintReverse(x - 1);
    cout << x << " ";
}

int fact(int x)
{
    // base case
    if (x == 1)
    {
        return 1;
    }
    int factorial = x * fact(x - 1);
}
int fib(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    return fib(x - 1) + fib(x - 2);
}
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n - 1);
}
int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    PrintReverse(x);
}