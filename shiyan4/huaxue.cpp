#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int maze[200][200];
int m, n;
int dp[200][200];

int dfs(int x, int y)
{
    int temp = 0, flag = 0;
    if (dp[x][y])
        return dp[x][y];
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && maze[x][y] > maze[nx][ny])
        {
            flag++;
            temp = max(temp, dfs(nx, ny) + 1);
        }
        else
            continue;
    }
    if (!flag)
        dp[x][y] = 1;
    dp[x][y] = temp;
    return dp[x][y];
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> maze[i][j];
    int res = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, dfs(i, j));
    cout << res+1 << endl;
}