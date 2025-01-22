#include <iostream>
using namespace std;
#include <queue>

int vis[201][201];
int step[201][201];
int start_x, start_y, end_x, end_y;
int dir[2][8] = {{2, 2, 1, -1, -2, -2, -1, 1}, {1, -1, -2, -2, -1, 1, 2, 2}};
queue<int> qx, qy;
int num;
int bfs();
void Init();

int main()
{
    int i = 1;
    cin>>num;
    for(i;i<=num;i++)
    {
        Init();
        cin >> start_x >> start_y >> end_x >> end_y;
        qx.push(start_x);
        qy.push(start_y);
        vis[start_y][start_x] = 1;
        step[start_y][start_x] = 0;
        int ans = bfs();
        cout << bfs() << endl;
    }
}

void Init()
{

    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= 200; j++)
        {
            vis[i][j] = 0;
            step[i][j] = 0;
        }
    while(!qx.empty())qx.pop();
    while(!qy.empty())qy.pop();
}

int bfs()
{
    int nx, ny, vx, vy;
    while (!qx.empty() && !qy.empty())
    {
        nx = qx.front();
        ny = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 8; i++)
        {
            vx = nx + dir[0][i];
            vy = ny + dir[1][i];
            if (vx == end_x && vy == end_y)
            {
                return step[ny][nx] + 1;
            }
            if (vx >= 1 && vx <= 200 && vy >= 1 && vy <= 200 && vis[vy][vx] == 0)
            {
                step[vy][vx] = step[ny][nx] + 1;
                vis[vy][vx] = 1;
                qx.push(vx);
                qy.push(vy);
            }
        }
    }
}