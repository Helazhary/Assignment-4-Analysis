
#include <iostream>
#include <vector>
using namespace std;

double bf_probability(int gen, double x)
{
    if (gen == 0)
    {
        return 1;
    }
    if(gen==1)
    {
        return 0.7;
    }
    else
    {
        double prev = bf_probability(gen - 1, x);
        double avg = ((1 + 0.7) + prev)/gen;
        return (0.7 * avg * x);
    }
}

double dp_probability(int gen, double x)
{
    if (gen == 0)
    {
        return x;
    }
    else
    {
        vector<double> dp{x};
        for (int i = 1; i <= gen; i++)
        {
            double prev = dp[i - 1];
            double avg = (1 + 0.7) / 2 * prev;
            double current = 0.7 * avg;
            dp.push_back(current);
        }
        return (dp[gen]);
    }
}

double brute_force(int g, double x) {
    if (g == 0) {
        return x;
    }
    double sum = 0;
    for (int i = 0; i < g; ++i) {
        sum += brute_force(i, x);
    }
    return 0.7 * sum / g;
}
int main()
{
    int generations = 3;
    double x = 0.5;
    cout << brute_force(generations, x) << "\n";
}
