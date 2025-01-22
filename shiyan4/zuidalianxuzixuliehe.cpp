#include <iostream>
using namespace std;

int dp[1000];
int n;
int s[1000];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    int ans = -0x3f3f3f;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + s[i], s[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}