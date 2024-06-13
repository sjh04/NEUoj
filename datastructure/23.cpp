#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(vector<pair<char, int>> &a, int p, int r)
{
    int x = a[r].second;
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j].second <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void QuickSort(vector<pair<char, int>> &a, int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

void merge(vector<pair<char, int>> &a, int l, int m, int r)
{
    int n1 = m - l;
    int n2 = r - m;
    vector<pair<char, int>> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[m + i];
    }

    L[n1].second = 1000000000;
    R[n2].second = 1000000000;

    int i = 0, j = 0;
    for (int k = l; k < r; k++)
    {
        if (L[i].second <= R[j].second)
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

void merge_sort(vector<pair<char, int>> &a, int l, int r)
{
    if ((l + 1) < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<char, int>> a(n);
    vector<pair<char, int>> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    b = a;

    QuickSort(a, 0, n - 1);
    merge_sort(b, 0, n);

    for (int i = 0; i < n; i++)
    {
        if (a[i].first != b[i].first)
        {
            cout << "Not stable" << endl;
            break;
        }
        if (i == n - 1)
        {
            cout << "Stable" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }

    return 0;
}