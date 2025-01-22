#include <iostream>
#include <cstring>
using namespace std;

int n;
int sum[100];
int dp[100][100];
int s[100];
int main()
{
    while (cin >> n && n != 0)
    {
        memset(sum, 0, sizeof(sum));
        memset(dp, 0x3f3f3f, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            dp[i][i] = 0;
            dp[i + n][i + n] = 0;
            sum[i] = sum[i - 1] + s[i];
        }
        for (int i = 1; i <= n; i++)
        {
            sum[i + n] = sum[i + n - 1] + s[i];
        }
        for (int len = 1; len <= n - 1; len++)
            for (int l = 1; l <= 2 * n - len - 1; l++)
            {
                int r = l + len;
                for (int k = l; k <= r - 1; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }

        int ans = 0x3f3f3f;
        for (int i = 1; i <= n; i++)
            ans = min(ans, dp[i][i + n - 1]);
        cout << ans << endl;
    }
}