#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}