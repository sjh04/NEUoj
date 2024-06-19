#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

double optimalBST(vector<double> p, vector<double> q)
{
    int n = p.size();
    vector<vector<double>> m(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> s(n + 1, vector<double>(n + 1, 0));

    // 初始化伪节点的代价
    for (int i = 1; i <= n + 1; i++)
    {
        m[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // 动态规划计算最优BST
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j]; // W的递推公式
            for (int k = i; k <= j; k++)
            {
                double cost = m[i][k - 1] + m[k + 1][j] + w[i][j];
                if (cost < m[i][j])
                {
                    s[i][j] = k;
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[1][n];
}

int main()
{
    int n;
    cin >> n;
    vector<double> p(n);
    vector<double> q(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        cin >> q[i];
    }

    cout << optimalBST(p, q) << endl;

    return 0;
}
