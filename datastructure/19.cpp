#include <iostream>
#include <cmath>

using namespace std;

void koch(double x1, double y1, double x2,double y2,int n)
{
    if (n == 0)
    {
        cout << x1 << " " << abs(y1) << endl;
    }
    else
    {
        double dx = (x2 - x1) / 3.0;
        double dy = (y2 - y1) / 3.0;
        double x3 = x1 + dx;
        double y3 = y1 + dy;
        double x4 =x2 - dx;
        double y4 = y2 - dy;
        double x5 = x3 + (x4 - x3) / 2.0 + (y4 - y3) * sqrtl(3.0) / 2.0;
        double y5 = y3 + (x3 - x4) * sqrtl(3.0) / 2.0 + (y4 - y3) / 2.0;
        koch(x1, y1, x3, y3, n - 1);
        koch(x3, y3, x5, y5, n - 1);
        koch(x5, y5, x4, y4, n - 1);
        koch(x4, y4, x2, y2, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    koch(0, 0, 100, 0, n);
    cout << 100 << " " << 0 << endl;
    return 0;
}