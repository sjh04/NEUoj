#include <iostream>

using namespace std;

int extendedGCD(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int x, y;
    int gcd = extendedGCD(a, b, x, y);
    cout << x << " " << y << endl;

    return 0;
}