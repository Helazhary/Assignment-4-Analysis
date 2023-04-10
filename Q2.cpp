#include <iostream>
#include <vector>
using namespace std;

int coin_change(vector<int> S, int N)
{
    vector<int> ways(N + 1, 0);
    ways[0] = 1;
    for (int i = 0; i < S.size(); i++)
    {
        int s = S[i];
        for (int j = s; j <= N; j++)
        {
            ways[j] += ways[j - s];
        }
    }
    return ways[N];
}

 /*
    N = number of coin denominations
    M = number of cents
    T(n) = arithmetic operations
    T(n) = nested summation ~ M*N
    = order of O(N*M) time and space complexity

  */

int main()
{
    vector<int> S = {1, 2, 3};
    int N = 5;
    cout << coin_change(S, N) << "\n";
}