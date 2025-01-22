#include <iostream>
#include <string.h>
using namespace std;

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // 四个方向，前四个为上下左右
int m, n, x, y;
char map[100][100];
int vis[100][100];
void dfs(int y, int x);
int cnt;

int main()
{
    while (cin >> m >> n >> x >> y && m != 0 && n != 0 && x != 0 && y != 0)
    {
        memset(vis, 0, sizeof(vis));
        memset(map, '\0', sizeof(map));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
            }
        cnt = 0;
        dfs(y, x);
        cout << cnt << endl;
    }
}

void dfs(int y, int x)
{
    int i;
    if (vis[y][x])
        return;
    vis[y][x] = 1;
    for (i = 0; i < 8; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if (nx >= 0 && nx <= n+1 && ny >= 0 && ny <= m+1)
        {
            if (map[ny][nx] != 'X' && i <= 3)
                cnt++;
            if (map[ny][nx] == 'X')
                dfs(ny, nx);
        }
    }
}