#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int dp[n][n];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Length of the chain
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            // Try all possible positions to split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    // Matrices:
    // A1 = 10 x 20
    // A2 = 20 x 30
    // A3 = 30 x 40
    // A4 = 40 x 30

    int p[] = {10, 20, 30, 40, 30};

    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum number of multiplications: "
         << matrixChainMultiplication(p, n);

    return 0;
}
