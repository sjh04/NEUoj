#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    vector<int> w(q);
    for (int i = 0; i < q; i++)
    {
        cin >> w[i];
    }
    int count = 0;

    for (int i = 0; i < q; i++)
    {
        int right = n;
        int left = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (w[i] == v[mid])
            {
                count++;
                break;
            }
            else if (w[i] < v[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}