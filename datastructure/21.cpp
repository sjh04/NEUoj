#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<int> &a, vector<int> &b, int k)
{
    vector<int> c(k + 1);
    for (int i = 0; i < a.size(); i++)
    {
        c[a[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > k)
        {
            k = a[i];
        }
    }
    vector<int> b(n + 1);
    counting_sort(a, b, k);
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
    return 0;
}