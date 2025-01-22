#include <iostream>
using namespace std;

int n, c, w[1000]; // num,capacity,weight
int dp[10000];     // 容量为[]时能装的最大重量

int main()
{
    cin >> n >> c;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = c; j >= 1; j--)
            if (j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
    cout << dp[c] << endl;
}