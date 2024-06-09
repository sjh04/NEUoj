#include <iostream>
#include <vector>

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
        for (int j = 0; j < n; j++)
        {
            if (w[i] == v[j])
            {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}