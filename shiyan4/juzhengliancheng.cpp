#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 50;
int n, p[maxn], q[maxn], dp[maxn][maxn];
int min(int x, int y)
{
    if (x <= y)
        return x;
    return y;
}

void Init()
{
    cin >> n;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> q[i];
        dp[i][i] = 0;
    }
}

void func()
{

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l <= n; l++)
        {
            int r = l + len - 1;
            for (int m = l; m <= r - 1; m++)
            {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + p[l] * q[m] * q[r]);
            }
        }
    }
}
int main()
{
    Init();
    func();

    cout << dp[1][n] << endl;
    return 0;
}
