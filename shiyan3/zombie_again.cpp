#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int x, y;
    int t, et; // 剩余时间,eat消化的剩余时间
};

queue<node> q;
char maze[201][201];
int vis[201][201];
int t, p;
int m, n;
int start_x, start_y, end_x, end_y, eat_x, eat_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

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
        int nx, ny, px, py;
        node now = q.front();
        q.pop();
        nx = now.x;
        ny = now.y;
        // cout<<"当前x位置:   "<<nx<<"当前y位置:   "<<ny<<endl;
        for (int i = 0; i < 4; i++)
        {
            node next;
            px = nx + dx[i];
            py = ny + dy[i];

            if (px >= 1 && px <= m && py >= 1 && py <= n && !vis[px][py] && maze[px][py] != '#' && now.t - 1 > 0) // 边界检查
            {
                if (px == eat_x && py == eat_y && (now.et == 0 || now.et == 1))
                {
                    next.x = start_x;
                    next.y = start_y;
                    next.et = t;
                    next.t = now.t - 1;
                    q.push(next);
                    memset(vis, 0, sizeof(vis)); // 被吃了就清空数组vis，并回起点
                    continue;
                }

                if (px == end_x && py == end_y)
                    return (p - now.t + 1);
                else
                {
                    next.t = now.t - 1;
                    if (now.et > 0)
                        next.et = now.et - 1;
                    else
                        next.et = 0;
                    next.x = px;
                    next.y = py;
                    vis[px][py] = 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

void Init()
{
    cin >> m >> n >> t >> p;
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
            if (maze[i][j] == '@')
            {
                eat_x = i;
                eat_y = j;
            }
        }
    node temp;
    temp.x = start_x;
    temp.y = start_y;
    temp.t = p;
    temp.et = 0;
    q.push(temp);
}