#include <iostream>
#include <queue>
#include <map>
using namespace std;

int maze[3][3];
int num;
queue<int> q;
map<int, int> m; // 用于存储对应状态的step
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
// 左下右上
void Init();
bool can_move(int now, int i);
int bfs();
int move(int now, int i);

int main()
{
    Init();
    cout << bfs() << endl;
}

void Init()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> maze[i][j];
            num = num * 10 + maze[i][j];
        }
    q.push(num);
    m[num] = 0;
}

bool can_move(int now, int i)
{
    int a[3][3];
    int zx, zy; // 0的坐标
    for (int i = 2; i >= 0; i--)
        for (int j = 2; j >= 0; j--)
        {
            a[i][j] = now % 10;
            now /= 10;
            if (a[i][j] == 0)
            {
                zx = i, zy = j;
            }
        }
    int nx, ny;
    nx = zx + dx[i];
    ny = zy + dy[i]; // 新位置
    if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)//越界检查
        return true;
    else
        return false;
}

int bfs()
{
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (can_move(now, i))
            {
                int next = move(now, i);
                if (next == 123456780)
                    return m[now]+1;
                else if (m.count(next) == 0)
                {
                    m[next] = m[now] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int move(int now, int i)
{
    int a[3][3];
    int zx, zy; // 0的坐标
    for (int i = 2; i >= 0; i--)
        for (int j = 2; j >= 0; j--)
        {
            a[i][j] = now % 10;
            now /= 10;
            if (a[i][j] == 0)
            {
                zx = i, zy = j;
            }
        }
    int nx, ny;
    nx = zx + dx[i];
    ny = zy + dy[i];
    int temp = a[nx][ny];
    a[nx][ny] = 0;
    a[zx][zy] = temp;
    int ret=0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            ret = ret * 10 + a[i][j];
        }
    return ret;
}
