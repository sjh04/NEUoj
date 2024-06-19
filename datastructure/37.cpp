#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int matrixChainMultiplication(vector<int> &dims)
{
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // l is the chain length.
    for (int l = 2; l <= n; ++l)
    { // l = 2 to n
        for (int i = 1; i <= n - l + 1; ++i)
        { // i = 1 to n - l + 1
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int q = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dims;
    for (int i = 0; i < n; ++i)
    {
        int r, c;
        cin >> r >> c;
        if (dims.empty())
        {
            dims.push_back(r);
        }
        dims.push_back(c);
    }

    // Calculate the minimum number of scalar multiplications
    int result = matrixChainMultiplication(dims);
    cout << result << endl;

    return 0;
}
