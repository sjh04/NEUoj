#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

string s1, s2;
int a[N], b[N], c[N];

int main()
{
    cin >> s1 >> s2;
    int j = 1, k = 1; // a、b数组的下标都是从1开始的
    for (int i = s1.size() - 1; i >= 0; i--)
        a[j++] = s1[i] - '0';
    for (int i = s2.size() - 1; i >= 0; i--)
        b[k++] = s2[i] - '0';

    int ma = max(s1.size(), s2.size()); // 记录最大长度
    int ans = 0;
    for (int i = 1; i <= ma; i++)
    {
        ans = ans + (a[i] + b[i]);
        c[i] = ans % 10;
        ans = ans / 10;
    }

    if (ans)
        c[++ma] = ans; //**一定要注意最后是否会向前进一
    for (int i = ma; i >= 1; i--)
    {
        cout << c[i];
    }
    return 0;
}