#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void merge(vector<int> &a, int l, int m, int r, int &count)
{
    int n1 = m - l;
    int n2 = r - m;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[m + i];
    }

    L[n1] = numeric_limits<int>::max();
    R[n2] = numeric_limits<int>::max();

    int i = 0, j = 0;
    for (int k = l; k < r; k++)
    {
        count++;
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &a, int l, int r, int &count)
{
    if ((l + 1) < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m, count);
        merge_sort(a, m, r, count);
        merge(a, l, m, r, count);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    merge_sort(a, 0, n, count);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << count << endl;

    return 0;
}