#include <iostream>
#include <vector>
using namespace std;

double brute_force(int gen, double x)
{
    if (gen == 0)
    {
        return x;
    }
    double sum = 0;
    for (int i = 0; i < gen; i++)
    {
        sum += brute_force(i, x);
    }
    return 0.7 * (sum / gen);
}

double dp_probability(int gen, double x)
{

    double sum = 0;
    vector<double> dp{x};
    for (int i = 1; i <= gen; i++)
    {
        sum += dp[i - 1];
        double avg = sum / i;
        double current = 0.7 * avg;
        dp.push_back(current);
    }
    return (dp[gen]);
}
/*
n = generations
T(n) = arithemtic operations
T(n) = summation from 1-n of 1 (constant operations)
 = O(n)
*/

int main()
{
    int generations = 3;
    double x = 0.5;
    cout << brute_force(generations, x) << "\n";
    cout << dp_probability(generations, x) << "\n";
}