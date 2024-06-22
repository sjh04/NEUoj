#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long myPower(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b / 2;
    }

    return result;
}

int main()
{
    long long a, b;
    long long result;
    cin >> a >> b;
    result = myPower(a, b);
    cout << result;
    return 0;
}