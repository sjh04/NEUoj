#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 递归函数生成所有子集的和
void generate_sums(const vector<int> &a, int index, int current_sum, unordered_set<int> &sums)
{
    if (index == a.size())
    {
        sums.insert(current_sum);
        return;
    }
    // 不包括当前元素
    generate_sums(a, index + 1, current_sum, sums);
    // 包括当前元素
    generate_sums(a, index + 1, current_sum + a[index], sums);
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

    int q;
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }

    unordered_set<int> sums;
    generate_sums(a, 0, 0, sums);

    for (int i = 0; i < q; i++)
    {
        if (sums.find(m[i]) != sums.end())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
