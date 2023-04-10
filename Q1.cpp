#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxProfit(int sp[], int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
     //initialized 2d array/table with 0's

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                dp[i][j] = max(dp[i - 1][j], sp[i - 1] + dp[i][j - i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main()
{

    int n = 5;
    int sp[] = {1, 5, 8, 9, 10};

    cout << "Max selling price: " << MaxProfit(sp, n) << "\n";
  /*
    N = number of divisions of the rods
    M = Length of the pipe
    T(n) = arithmetic operations
    T(n) = nested summation ~ M*N
    = order of O(N*M) time and space complexity

  */
}
