#include <iostream>
#include <queue>
using namespace std;

struct point
{
    char ch;
    int vis;
    int step;
};

queue<int> qx, qy;
int start_x, start_y, end_x, end_y;
int dir[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
point map[13][13];

int bfs();
void input();

int main()
{
    input();
    int ans = bfs();
    cout << ans;
}

void input()
{

    cin >> start_y >> start_x >> end_y >> end_x;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 12; j++)
        {
            cin >> map[i][j].ch;
            map[i][j].vis = 0;
        }
    qx.push(start_x);
    qy.push(start_y);
    map[start_y][start_x].vis = 1;
    map[start_y][start_x].step = 0;
}

int bfs()
{
    while (!qx.empty() && !qy.empty())
    {
        int nx = qx.front();
        int ny = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 4; i++)
        {

            int vx = nx + dir[0][i];
            int vy = ny + dir[1][i];
            if (vx == end_x && vy == end_y)
                return map[ny][nx].step + 1;
            else if (vx > 0 && vx <= 12 && vy > 0 && vy <= 12 && !map[vy][vx].vis && map[vy][vx].ch == '.')
            {
                map[vy][vx].vis = 1;
                map[vy][vx].step = map[ny][nx].step + 1;
                qx.push(vx);
                qy.push(vy);
            }
        }
    }
}