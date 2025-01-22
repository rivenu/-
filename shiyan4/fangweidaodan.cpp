#include <iostream>
#include <cstring>
using namespace std;

int n;
int p[100];
int res;
int dp[100];

void func()
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (p[j] >= p[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        res = max(res, dp[i]);
    }
}

int main()
{
    while (cin >> n && n != 0)
    {
        res = 0;
        memset(p, 0, sizeof(p));
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
            cin >> p[i];
        func();
        cout << res<<endl;
    }
}