#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int m = v[0];
    for (int i = 0; i < n; i++)
    {
        m = lcm(m, v[i]);
    }

    cout << m;
    return 0;
}