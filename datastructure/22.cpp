#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(vector<int> &a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void QuickSort(vector<int> &a, int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q = Partition(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        if (i == q)
        {
            cout << "[" << a[i] << "]";
        }
        else
        {
            cout << a[i];
        }
    }
    cout << endl;
    QuickSort(a, 0, n - 1);

    return 0;
}