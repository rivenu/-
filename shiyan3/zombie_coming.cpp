#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int nx, ny, nt;
    int step;
};

queue<node> q;
char maze[201][201];
int vis[201][201];
int t;
int m, n;
int start_x, start_y, end_x, end_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
// 左下右上

void Init();
int bfs();

int main()
{
    Init();
    cout << bfs() << endl;
}

int bfs()
{
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        int nx = now.nx, ny = now.ny;
        for (int i = 0; i < 4; i++)
        {
            node next;
            int px = nx + dx[i], py = ny + dy[i];

            if (px >= 1 && px <= m && py >= 1 && py <= n && !vis[px][py]) // 边界检查
            {
                next.nx = px;
                next.ny = py;
                if (maze[px][py] == 'w')
                {
                    next.nt = now.nt - 1;
                }
                else
                {
                    next.nt = now.nt; // 非 'w' 格子不消耗时间
                }
                if (next.nt > 0)
                {
                    if (next.nx == end_x && next.ny == end_y)
                    {
                        return now.step + 1;
                    }
                    next.step = now.step + 1;
                    q.push(next);
                    vis[px][py] = 1;
                }
            }
        }
    }
    return -1;
}

void Init()
{
    cin >> m >> n >> t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '!')
            {
                start_x = i;
                start_y = j;
                vis[i][j] = 1;
            }
            if (maze[i][j] == '+')
            {
                end_x = i;
                end_y = j;
            }
        }
    node temp;
    temp.nx = start_x;
    temp.ny = start_y;
    temp.nt = t;
    temp.step = 0;
    q.push(temp);
}