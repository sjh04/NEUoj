#include <iostream>
#include <vector>
using namespace std;

void primeFactorization(int n)
{
    int m = n;
    vector<int> v;

    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        v.push_back(n);
    }

    cout << m << ": ";
    for (auto &i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    primeFactorization(n);
    return 0;
}