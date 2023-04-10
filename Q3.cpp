#include <iostream>
#include <vector>
using namespace std;

//using the same approach as the coin change problem in Q3
int Options(vector<int> allowedMeals, int calorieAllowance)
{
    int n = allowedMeals.size();
    vector<int> dp(calorieAllowance + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = allowedMeals[i]; j <= calorieAllowance; j++)
        {
            dp[j] += dp[j - allowedMeals[i]];
        }
    }
    return dp[calorieAllowance];
}
/*
    N = number of meal combinations
    M = daily caloric intake value
    T(n) = arithmetic operations
    T(n) = nested summation ~ M*N
    = order of O(N*M) time and space complexity
*/

int main()
{
    vector<int> allowedMeals = {200, 500, 600, 300};
    int calorieAllowance = 1000;
    cout << "Varieties: " << Options(allowedMeals, calorieAllowance) << endl;
}
